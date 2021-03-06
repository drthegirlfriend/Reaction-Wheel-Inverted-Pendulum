
double update_LQR(double * u)
{
  //double yr = -15.495174026892334 * (-M_PI + u[0]) - 3.4400308059648723 * u[1] + 0.01343605009462376 * u[2]; //weich
  double yr = -26.8591906126124*(-M_PI + u[0]) - 2.8517595773639597*u[1] + 0.018993162921974713*u[2];
  return yr;
}
//======================================================================
double u_0[3] = {3.141592653589793, 0, 0};
double y_0[3] = {3.141592653589793, 0, 0};
void update_nssm_0(double *u, double *y)
{
y[0] = u[0];
y[1] = u[1];
y[2] = u[2];
}
double u_1C[2] = {0, 0};
double y_1[1] = {0};
void update_tfm_1(double *uC, double *y)
{
static double u_10[1] = {0};
u_10[0] = uC[0];
static double u_11[1] = {0};
u_11[0] = uC[1];
static double x_10[1] = {0};
x_10[0] = u_10[0];
static double x_11[1] = {0};
x_11[0] = -1*u_11[0];
y[0] = x_10[0] + x_11[0];
}
double u_2[4] = {3.141592653589793, 0, 0, 0};
double y_2[1] = {0.};
void update_nssm_2(double *u, double *y)
{
y[0] = -26.8591906126124*(-M_PI + u[0]) - 2.8517595773639597*u[1] + 0.018993162921974713*u[2];
}
double u_3[2] = {0, 0};
double y_3[1] = {-3.141592653589793};
void update_nssm_3(double *u, double *y)
{
y[0] = 0.03723120381484709*(-84.38063590995105 + 26.8591906126124*u[0] + 1.*u[1]);
}
double u[3] = {3.141592653589793, 0, 0};
double y[2] = {0., -3.141592653589793};
void update_scm(double *u, double *y)
{
u_0[0] = u[0];
u_0[1] = u[1];
u_0[2] = u[2];
update_nssm_0(u_0, y_0);
u_1C[0] = y_0[0];
u_1C[1] = y_3[0];
update_tfm_1(u_1C, y_1);
u_2[0] = y_1[0];
u_2[1] = y_0[1];
u_2[2] = y_0[2];
update_nssm_2(u_2, y_2);
y[0] = y_2[0];
u_3[0] = y_1[0];
u_3[1] = y_2[0];
update_nssm_3(u_3, y_3);
y[1] = y_3[0];
}
