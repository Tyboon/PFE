/*===========================================================================*
 * spread_ind.c
 *
 * Compile:
 *   gcc -lm -o spread_ind spread_ind.c
 *
 * Usage:
 *   spread_ind [<param_file>] <data_file> <reference_set> <output_file>
 *
 *   <param_file> specifies the name of the parameter file for spread_ind;
 *     the file has the following format:
 *
 *       dim <integer>
 *       obj <+|-> <+|-> ...
 *
 *     The first line defines the number of objectives, the second for each
 *     objective whether it is minimized (-) or maximized.
 *     If the parameter file is omitted, default parameters are taken (all
 *     objective are to be minimized) and the number of objectives
 *     is determined from the data file.
 *
 *   <data_file> specifies a file that contains the output of one or
 *     several runs of a selector/variator pair; the format corresponds to
 *     the one defined in the specification of the PISA monitor program.
 *
 *   <reference_set> is the name of a file that contains the reference set
 *     according to which the indicator values are calculated; the file
 *     format is the same as for the data file.
 *
 *   <output_file> defines the name of the file to which the computed
 *     indicator values are written to.
 */

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define error(X,Y)  if (X) fprintf(stderr, Y "\n"), exit(1)

#define MAX_LINE_LENGTH  2048 /* maximal length of lines in the files */
#define MAX_STR_LENGTH  256 /* maximal length of strings in the files */

int  dim;  /* number of objectives */
int  *obj;  /* obj[i] = 0 means objective i is to be minimized */


double  calc_ind_value(double  *a, int  size_a, double  *b, int  size_b)
{
    int  i, j, k, l;
    int size_bounds;
    int *bounds;
    int bool;
    int size_c;
    double *c;
    double *dists;
    double *nneighbs;
    int tmp;
    double spread;
    double sum;
    double mean;

    /* search boundaries */
    size_bounds = 2*dim;
    bounds = malloc(2 * dim * sizeof(int));
    error(bounds == NULL, "memory overflow");
    for (k = 0; k < 2 * dim; k++)
      bounds[k] = 0;    for (i = 0; i < size_a; i++)
      for (k = 0; k < dim; k++)
	if (a[i * dim + k] < bounds[k/2])
	  bounds[k/2] = i;
	else if (a[i * dim + k] > bounds[k/2])
	  bounds[k/2+1] = i;

    /* uniquify boundaries */
    for (i = 0; i < size_bounds; i++)
      for (j = 0; j < i; j++)
	if (bounds[i] == bounds[j])
	  if (i != size_bounds) {
	    size_bounds--;
	    bounds[i] = bounds[size_bounds];
	    j = -1;
	  }

    /* remove boundaries from b */
    for (i = 0; i < size_bounds; i++)
      for (j = 0; j < size_b; j++) {
	bool = 1;
	for (k = 0; k < dim && j < size_b; k++)
	  if (b[j * dim + k] == a[bounds[i] * dim + k])
	    bool = 0;
	if (!bool) {
	  size_b--;
	  for (k = 0; k < dim; k++)
	    b[j * dim + k] = b[size_b * dim + k];
	  j = -1;
	}
      }

    /* create c */
    size_c = size_bounds + size_b;
    c = malloc(dim * size_c * sizeof(double));
    error(c == NULL, "memory overflow");
    for (i = 0; i < size_bounds; i++)
      for (k = 0; k < dim; k++)
	c[i * dim + k] = a[bounds[i] * dim + k];
    for (i = 0; i < size_b; i++)
      for (k = 0; k < dim; k++)
	c[(size_bounds + i) * dim + k] = b[i * dim + k];

    /* compute distances (manhattan) */
    dists = malloc(size_c * size_c * sizeof(double));
    error(dists == NULL, "memory overflow");
    for (i = 1; i < size_c; i++)
      for (j = 0; j < i; j++)
	if (i != j)
	  for (k = 0; k < dim; k++)
	    dists[i * size_c + j] += abs(c[i * dim + k] - c[j * dim + k]);
    for (i = 0; i < size_c; i++)
      for (j = 0; j < i; j++)
	dists[j * size_c + i] = dists[i * size_c + j];

    printf("d\n");
    for (i = 0; i < size_c * size_c; i++)
      printf("%f\n", dists[i]);

    /* compute nearest-neighbors */
    nneighbs = malloc((dim * size_b + (dim - 1) * size_bounds) * sizeof(double));
    error(nneighbs == NULL, "memory overflow");
    for (i = 0; i < size_bounds; i++) {
      j = 0;
      for (k = j; k < size_c; k++) {
	if (dists[i*size_c + k] > 0 &&
	    (!nneighbs[i*(dim-1)] || dists[i*size_c + k] <= nneighbs[i*(dim-1)])) {
	  nneighbs[i*(dim-1)+j] = dists[i*size_c + k];
	  for (l = 0; l < j; l++)
	    if (nneighbs[i*(dim-1)+j-l] > nneighbs[i*(dim-1)+j-l-1]) {
	      tmp = nneighbs[i*(dim-1)+j-l-1];
	      nneighbs[i*(dim-1)+j-l-1] = nneighbs[i*(dim-1)+j-l];
	      nneighbs[i*(dim-1)+j-l] = tmp;
	    }
	  if (j + 1 < dim - 1)
	    j++;
	}
      }
    }
    for (i = size_bounds; i < size_c; i++) {
      j = 0;
      for (k = 0; k < size_c; k++)
	if (dists[i*size_c + k] > 0 &&
	    (!nneighbs[i*(dim-1)] || dists[i*size_c + k] <= nneighbs[i*(dim-1)])) {
	  nneighbs[i*dim-size_bounds+j] = dists[i*size_c + k];
	  for (l = 0; l < j; l++)
	    if (nneighbs[i*dim-size_bounds+j-l] > nneighbs[i*dim-size_bounds+j-l-1]) {
	      tmp = nneighbs[i*dim-size_bounds+j-l-1];
	      nneighbs[i*dim-size_bounds+j-l-1] = nneighbs[i*dim-size_bounds+j-l];
	      nneighbs[i*dim-size_bounds+j-l] = tmp;
	    }
	  if (j + 1 < dim)
	    j++;
	}
    }

    printf("n\n");
    for (i = 0; i < (dim * size_b + (dim - 1) * size_bounds); i++)
      printf("%f\n", nneighbs[i]);

    /* compute spread */
    for (i = 0; i < (dim * size_b + (dim - 1) * size_bounds); i++)
      sum += nneighbs[i];
    printf("sum: %f\n", sum);
    mean = sum / (dim * size_b + (dim - 1) * size_bounds);
    printf("mean: %f\n", mean);
    for (i = 0; i < (dim * size_b + (dim - 1) * size_bounds); i++)
      spread += abs(nneighbs[i] - mean);
    spread = (1 + spread)/(1 + sum);

    printf("spread\n%f\n", spread);
    return spread;
}

void  read_params(FILE  *fp)
{
    char str[MAX_STR_LENGTH];
    int  i;
    
    fscanf(fp, "%s", str);
    error(strcmp(str, "dim") != 0, "error in parameter file");
    fscanf(fp, "%d", &dim);
    error(dim <= 0, "error in parameter file");
    obj = malloc(dim * sizeof(int));
    error(obj == NULL, "memory overflow");

    fscanf(fp, "%s", str);
    error(strcmp(str, "obj") != 0, "error in parameter file");
    for (i = 0; i < dim; i++) {
	fscanf(fp, "%s", str);
	error(str[0] != '-' && str[0] != '+', "error in parameter file");
	if (str[0] == '-')
	    obj[i] = 0;
	else
	    obj[i] = 1;
    }
}

void  set_params(void)
{
    int  i;
    
    obj = malloc(dim * sizeof(int));
    error(obj == NULL, "memory overflow");
    for (i = 0; i < dim; i++)
	obj[i] = 0;
}

void  check_file(FILE  *fp, int  *no_runsp, int  *max_pointsp)
    /* determines the maximum number of points and the number of runs
       for the data resp. the reference set file; if the array v is
       specified, the data read in will be stored in v
    */
{
    char  line[MAX_STR_LENGTH];
    int  i, j;
    int  new_run;
    int  no_points;
    double  number;

    no_points = 0;
    *max_pointsp = 0;
    *no_runsp = 0;
    new_run = 1;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
	if (sscanf(line, "%lf", &number) != 1)
	    new_run = 1;
	else {
	    if (new_run == 1)
	    {
		(*no_runsp)++;
		if (*max_pointsp < no_points)
		    *max_pointsp = no_points;
		no_points = 0;
	    }
	    new_run = 0;
	    i = 0;
	    for (j = 1; j < dim; j++) {
		while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
		    i++;
		error(sscanf(&(line[i]), "%lf", &number) <= 0,
		      "error in data or reference set file");
		while (line[i] == ' ' && line[i] != '\0')
		    i++;
	    }
	    no_points++;
	}
    }
    if (*max_pointsp < no_points)
	*max_pointsp = no_points;
}

int  determine_dim(FILE  *fp)
{
    char  line[MAX_STR_LENGTH];
    int  i, no_obj;
    int  line_found, number_found;
    double  number;
    
    no_obj = 0;
    line_found = 0;
    while (!line_found && fgets(line, MAX_LINE_LENGTH, fp) != NULL)
        line_found = sscanf(line, "%lf", &number);
    if (line_found) {
	i = 0;
	do {
	    no_obj++;
	    while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
		i++;
	    number_found = sscanf(&(line[i]), "%lf", &number);
	    while (line[i] == ' ' && line[i] != '\0')
		i++;
	} while (number_found == 1);
    }
    
    return no_obj;
}

void  read_file(FILE  *fp, int  *no_pointsp, double  *points)
{
    char  line[MAX_STR_LENGTH];
    int  i, j, k;
    int  reading;
    double  number;

    k = 0;
    reading = 0;
    *no_pointsp = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (sscanf(line, "%lf", &number) != 1) {
	    if (reading)
	        break;
	}
	else {
	    reading = 1;
	    points[k++] = number;
	    i = 0;
	    for (j = 1; j < dim; j++) {
		while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
		    i++;
		error(sscanf(&(line[i]), "%lf", &number) <= 0,
		      "error in data or reference set file");
		points[k++] = number;
		while (line[i] == ' ' && line[i] != '\0')
		    i++;
	    }
	    (*no_pointsp)++;
	}
    } 
}

int  main(int  argc, char  *argv[])
{
    int  i;
    int  no_runs;  /* number of runs */
    int  max_points;  /* maximum number of points per run */
    int  ref_set_size;  /* number of points in the reference set */
    int  curr_run_size;  /* number of points associated with the current run */
    double  *ref_set;  /* reference set */
    double  *curr_run; /* objective vectors fur current run */
    double  ind_value;
    FILE  *fp, *out_fp;
    
    error(argc != 4 && argc != 5,
	  "Spread indicator - wrong number of arguments:\nspread_ind [parFile] datFile refSet outFile");

    /* set parameters */
    if (argc == 5) {
	fp = fopen(argv[1], "r");
	error(fp == NULL, "parameter file not found");
	read_params(fp);
	fclose(fp);
    }
    else {
	fp = fopen(argv[1], "r");
	error(fp == NULL, "data file not found");
	dim = determine_dim(fp);
	error(dim < 1, "error in data file");
	fclose(fp);
	obj = malloc(dim * sizeof(int));
	error(obj == NULL, "memory overflow");
	for (i = 0; i < dim; i++)
	    obj[i] = 0;
    }

    /* read reference set */
    if (argc == 5)
	fp = fopen(argv[3], "r");
    else
	fp = fopen(argv[2], "r");
    error(fp == NULL, "reference set file not found");
    check_file(fp, &no_runs, &max_points);
    error(no_runs != 1 || max_points < 1, "error in reference set file");
    ref_set = malloc(dim * max_points * sizeof(double));
    error(ref_set == NULL, "memory overflow");
    rewind(fp);
    read_file(fp, &ref_set_size, ref_set);
    fclose(fp);
    no_runs = 0;
    max_points = 0;
    
    /* check data file */
    if (argc == 5)
	fp = fopen(argv[2], "r");
    else
	fp = fopen(argv[1], "r");
    error(fp == NULL, "data file not found");
    check_file(fp, &no_runs, &max_points);
    error(no_runs < 1 || max_points < 1, "error in data file");
    curr_run = malloc(dim * max_points * sizeof(double));
    rewind(fp);

    /* process data */
    if (argc == 5)
	out_fp = fopen(argv[4], "w");
    else
	out_fp = fopen(argv[3], "w");
    error(out_fp == NULL, "output file could not be generated");
    while (no_runs > 0) {
	read_file(fp, &curr_run_size, curr_run);
	ind_value = calc_ind_value(ref_set, ref_set_size,
				   curr_run, curr_run_size);
	fprintf(out_fp, "%.9e\n", ind_value);
	no_runs--;
    }
    fclose(out_fp);
    fclose(fp);

    return 0;
}
