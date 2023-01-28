/*
Sanjay Kharche. June 6, 2018.

Solve Shi et al. 2009 using SRK Sundials solver.
Time soutions.
Sensitivity indicies.

   There are a total of 34 entries in the algebraic variable array.
   There are a total of 14 entries in each of the rate and state variable arrays.
   There are a total of 88 entries in the constant variable array.

 * VOI is t in component environment (second).
 * ALGEBRAIC[18] is Pi in component TempCDa (UnitP).
 * STATES[0] is Pi in component TempRLC (UnitP).
 * ALGEBRAIC[30] is Qo in component TempRC (UnitQ).
 * ALGEBRAIC[10] is Qo in component TempCDv (UnitQ).
 * ALGEBRAIC[19] is Pi in component TempCDa (UnitP).
 * STATES[1] is Pi in component TempRLC (UnitP).
 * ALGEBRAIC[31] is Qo in component TempRC (UnitQ).
 * ALGEBRAIC[11] is Qo in component TempCDv (UnitQ).
 * ALGEBRAIC[6] is Pi in component TempCDv (UnitP).
 * ALGEBRAIC[22] is Qo in component TempCDa (UnitQ).


 * CONSTANTS[0] is CVao in component ParaHeart (UnitCV). This is the paramter for aortic value opening/blood flow.


 * ALGEBRAIC[4] is E in component EVentricle (UnitE).
 * STATES[2] is V in component TempCDv (UnitV).
 * CONSTANTS[1] is PlvIni in component ParaHeart (UnitP).
 * CONSTANTS[2] is VlvIni in component ParaHeart (UnitV).
 * ALGEBRAIC[8] is Tao in component TempCDv (dimensionless).
 * CONSTANTS[3] is Vlv0 in component ParaHeart (UnitV).
 * CONSTANTS[4] is CVmi in component ParaHeart (UnitCV).
 * ALGEBRAIC[16] is E in component EAtrium (UnitE).
 * STATES[3] is V in component TempCDa (UnitV).

// la represents left atrium in notation. These constants appear to regulate left atrial pressure and flow.
 * CONSTANTS[5] is PlaIni in component ParaHeart (UnitP).
 * CONSTANTS[6] is VlaIni in component ParaHeart (UnitV).
 * ALGEBRAIC[20] is Tao in component TempCDa (dimensionless).
 * CONSTANTS[7] is Vla0 in component ParaHeart (UnitV).
 * CONSTANTS[13] is ElaMax in component ParaHeart (UnitE).
 * CONSTANTS[14] is ElaMin in component ParaHeart (UnitE).


 * CONSTANTS[8] is ElvMax in component ParaHeart (UnitE).
 * CONSTANTS[9] is ElvMin in component ParaHeart (UnitE).
 * CONSTANTS[10] is T in component ParaHeart (second).
 * CONSTANTS[11] is Ts1 in component ParaHeart (dimensionless).
 * CONSTANTS[12] is Ts2 in component ParaHeart (dimensionless).
 * ALGEBRAIC[0] is mt in component EVentricle (second).
 * ALGEBRAIC[2] is et in component EVentricle (dimensionless).

 * CONSTANTS[15] is Tpwb in component ParaHeart (dimensionless). start of P wave time
 * CONSTANTS[16] is Tpww in component ParaHeart (dimensionless). end of P wave time.

 * ALGEBRAIC[12] is mt in component EAtrium (second).
 * ALGEBRAIC[14] is et in component EAtrium (dimensionless).
 * CONSTANTS[17] is EraMax in component ParaHeart (UnitE).
 * CONSTANTS[18] is EraMin in component ParaHeart (UnitE).
 * CONSTANTS[19] is PraIni in component ParaHeart (UnitP).
 * CONSTANTS[20] is VraIni in component ParaHeart (UnitV).
 * CONSTANTS[21] is ErvMax in component ParaHeart (UnitE).
 * CONSTANTS[22] is ErvMin in component ParaHeart (UnitE).
 * CONSTANTS[23] is PrvIni in component ParaHeart (UnitP).
 * CONSTANTS[24] is VrvIni in component ParaHeart (UnitV).
 * CONSTANTS[25] is CVpa in component ParaHeart (UnitCV).
 * CONSTANTS[26] is CVti in component ParaHeart (UnitCV).
 * CONSTANTS[27] is Vra0 in component ParaHeart (UnitV).
 * CONSTANTS[28] is Vrv0 in component ParaHeart (UnitV).
 * ALGEBRAIC[7] is Pi in component TempCDv (UnitP).
 * ALGEBRAIC[23] is Qo in component TempCDa (UnitQ).
 * CONSTANTS[29] is CVpa in component ParaHeart (UnitCV).
 * ALGEBRAIC[5] is E in component EVentricle (UnitE).
 * STATES[4] is V in component TempCDv (UnitV).
 * CONSTANTS[30] is PrvIni in component ParaHeart (UnitP).
 * CONSTANTS[31] is VrvIni in component ParaHeart (UnitV).
 * ALGEBRAIC[9] is Tao in component TempCDv (dimensionless).
 * CONSTANTS[32] is Vrv0 in component ParaHeart (UnitV).
 * CONSTANTS[33] is CVti in component ParaHeart (UnitCV).
 * ALGEBRAIC[17] is E in component EAtrium (UnitE).
 * STATES[5] is V in component TempCDa (UnitV).
 * CONSTANTS[34] is PraIni in component ParaHeart (UnitP).
 * CONSTANTS[35] is VraIni in component ParaHeart (UnitV).
 * ALGEBRAIC[21] is Tao in component TempCDa (dimensionless).
 * CONSTANTS[36] is Vra0 in component ParaHeart (UnitV).
 * CONSTANTS[37] is ErvMax in component ParaHeart (UnitE).
 * CONSTANTS[38] is ErvMin in component ParaHeart (UnitE).
 * CONSTANTS[39] is T in component ParaHeart (second).
 * CONSTANTS[40] is Ts1 in component ParaHeart (dimensionless).
 * CONSTANTS[41] is Ts2 in component ParaHeart (dimensionless).
 * ALGEBRAIC[1] is mt in component EVentricle (second).
 * ALGEBRAIC[3] is et in component EVentricle (dimensionless).
 * CONSTANTS[42] is EraMax in component ParaHeart (UnitE).
 * CONSTANTS[43] is EraMin in component ParaHeart (UnitE).
 * CONSTANTS[44] is Tpwb in component ParaHeart (dimensionless).
 * CONSTANTS[45] is Tpww in component ParaHeart (dimensionless).
 * ALGEBRAIC[13] is mt in component EAtrium (second).
 * ALGEBRAIC[15] is et in component EAtrium (dimensionless).
 * CONSTANTS[46] is ElaMax in component ParaHeart (UnitE).
 * CONSTANTS[47] is ElaMin in component ParaHeart (UnitE).
 * CONSTANTS[48] is PlaIni in component ParaHeart (UnitP).
 * CONSTANTS[49] is VlaIni in component ParaHeart (UnitV).
 * CONSTANTS[50] is ElvMax in component ParaHeart (UnitE).
 * CONSTANTS[51] is ElvMin in component ParaHeart (UnitE).
 * CONSTANTS[52] is PlvIni in component ParaHeart (UnitP).
 * CONSTANTS[53] is VlvIni in component ParaHeart (UnitV).
 * CONSTANTS[54] is CVao in component ParaHeart (UnitCV).
 * CONSTANTS[55] is CVmi in component ParaHeart (UnitCV).
 * CONSTANTS[56] is Vlv0 in component ParaHeart (UnitV).
 * CONSTANTS[57] is Vla0 in component ParaHeart (UnitV).
 * STATES[6] is Pi in component TempRLC (UnitP).
 * STATES[7] is Qo in component TempRLC (UnitQ).
 * CONSTANTS[58] is Rsas in component ParaSys (UnitR).
 * CONSTANTS[59] is Csas in component ParaSys (UnitC).
 * CONSTANTS[60] is Lsas in component ParaSys (UnitL).
 * CONSTANTS[61] is P0sas in component ParaSys (UnitP).
 * CONSTANTS[62] is Q0sas in component ParaSys (UnitQ).
 * ALGEBRAIC[32] is Pi in component TempR (UnitP).
 * STATES[8] is Qo in component TempRLC (UnitQ).
 * CONSTANTS[63] is Rsat in component ParaSys (UnitR).
 * CONSTANTS[64] is Csat in component ParaSys (UnitC).
 * CONSTANTS[65] is Lsat in component ParaSys (UnitL).
 * CONSTANTS[66] is P0sat in component ParaSys (UnitP).
 * CONSTANTS[67] is Q0sat in component ParaSys (UnitQ).
 * ALGEBRAIC[28] is Pi in component TempR (UnitP).
 * ALGEBRAIC[25] is Qo in component TempR (UnitQ).
 * CONSTANTS[68] is Rsar in component ParaSys (UnitR).
 * STATES[9] is Pi in component TempRC (UnitP).
 * ALGEBRAIC[27] is Qo in component TempR (UnitQ).
 * CONSTANTS[69] is Rscp in component ParaSys (UnitR).
 * CONSTANTS[70] is Rsvn in component ParaSys (UnitR).
 * CONSTANTS[71] is Csvn in component ParaSys (UnitC).
 * CONSTANTS[72] is P0svn in component ParaSys (UnitP).
 * STATES[10] is Pi in component TempRLC (UnitP).
 * STATES[11] is Qo in component TempRLC (UnitQ).
 * CONSTANTS[73] is Rpas in component ParaPul (UnitR).
 * CONSTANTS[74] is Cpas in component ParaPul (UnitC).
 * CONSTANTS[75] is Lpas in component ParaPul (UnitL).
 * CONSTANTS[76] is P0pas in component ParaPul (UnitP).
 * CONSTANTS[77] is Q0pas in component ParaPul (UnitQ).
 * ALGEBRAIC[33] is Pi in component TempR (UnitP).
 * STATES[12] is Qo in component TempRLC (UnitQ).
 * CONSTANTS[78] is Rpat in component ParaPul (UnitR).
 * CONSTANTS[79] is Cpat in component ParaPul (UnitC).
 * CONSTANTS[80] is Lpat in component ParaPul (UnitL).
 * CONSTANTS[81] is P0pat in component ParaPul (UnitP).
 * CONSTANTS[82] is Q0pat in component ParaPul (UnitQ).
 * ALGEBRAIC[29] is Pi in component TempR (UnitP).
 * ALGEBRAIC[24] is Qo in component TempR (UnitQ).
 * CONSTANTS[83] is Rpar in component ParaPul (UnitR).
 * STATES[13] is Pi in component TempRC (UnitP).
 * ALGEBRAIC[26] is Qo in component TempR (UnitQ).
 * CONSTANTS[84] is Rpcp in component ParaPul (UnitR).
 * CONSTANTS[85] is Rpvn in component ParaPul (UnitR).
 * CONSTANTS[86] is Cpvn in component ParaPul (UnitC).
 * CONSTANTS[87] is P0pvn in component ParaPul (UnitP).
 * RATES[2] is d/dt V in component TempCDv (UnitV).
 * RATES[3] is d/dt V in component TempCDa (UnitV).
 * RATES[4] is d/dt V in component TempCDv (UnitV).
 * RATES[5] is d/dt V in component TempCDa (UnitV).
 * RATES[0] is d/dt Pi in component TempRLC (UnitP).
 * RATES[7] is d/dt Qo in component TempRLC (UnitQ).
 * RATES[6] is d/dt Pi in component TempRLC (UnitP).
 * RATES[8] is d/dt Qo in component TempRLC (UnitQ).
 * RATES[9] is d/dt Pi in component TempRC (UnitP).
 * RATES[1] is d/dt Pi in component TempRLC (UnitP).
 * RATES[11] is d/dt Qo in component TempRLC (UnitQ).
 * RATES[10] is d/dt Pi in component TempRLC (UnitP).
 * RATES[12] is d/dt Qo in component TempRLC (UnitQ).
 * RATES[13] is d/dt Pi in component TempRC (UnitP).
*/

// my standard header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <time.h>
#include <cvodes/cvodes.h>
#include <nvector/nvector_serial.h>
#include <sundials/sundials_types.h>
#include <sundials/sundials_math.h>
#include <cvodes/cvodes_dense.h>

#define Ith(v,i)    		NV_Ith_S(v,i-1)       /* Ith numbers components 1..NEQ    */
#define IJth(A,i,j) 		DENSE_ELEM(A,i-1,j-1) /* IJth numbers rows,cols 1..NEQ    */
#define RTOL  	    	RCONST(1.0e-12)   /* scalar relative tolerance            */
#define ATOL        	RCONST(1.0e-6)   /* scalar absolute tolerance components */
#define MAXSTEPS    	5000

#define num_beats 100
#define NEQ  14                /* number of equations, ODEs, Shi 2009. */

#define dt 0.0001 // seconds.

// for parameter sweeps.
// #define CONSTANTS63   0.05  // RSAT.
//#define CONSTANTS58   0.003 
//#define CONSTANTS64   1.6 
//#define CONSTANTS65   0.0017 
//#define CONSTANTS68   0.5 
//#define CONSTANTS69   0.52 
//#define CONSTANTS70   0.075 

// 88 constants, some of which are initial conditions.
#define CONSTANTS0   350. 
#define CONSTANTS1   1.0 
#define CONSTANTS2   5.0 
#define CONSTANTS3   500 
#define CONSTANTS4   400. 
#define CONSTANTS5   1.0 
#define CONSTANTS6   4.0 
#define CONSTANTS7   20 
#define CONSTANTS8   2.5 
#define CONSTANTS9   0.1 
#define CONSTANTS10   1.0 
#define CONSTANTS11   0.3 
#define CONSTANTS12   0.45 
#define CONSTANTS13   0.25 
#define CONSTANTS14   0.15 
#define CONSTANTS15   0.92 
#define CONSTANTS16   0.09 
#define CONSTANTS17   0.25 
#define CONSTANTS18   0.15 
#define CONSTANTS19   1.0 
#define CONSTANTS20   4.0 
#define CONSTANTS21   1.15 
#define CONSTANTS22   0.1 
#define CONSTANTS23   1.0 
#define CONSTANTS24   10.0 
#define CONSTANTS25   350. 
#define CONSTANTS26   400. 
#define CONSTANTS27   20 
#define CONSTANTS28   500 
#define CONSTANTS29   350. 
#define CONSTANTS30   1.0 
#define CONSTANTS31   10.0 
#define CONSTANTS32   500 
#define CONSTANTS33   400. 
#define CONSTANTS34   1.0 
#define CONSTANTS35   4.0 
#define CONSTANTS36   20 
#define CONSTANTS37   1.15 
#define CONSTANTS38   0.1 
#define CONSTANTS39   1.0 
#define CONSTANTS40   0.3 
#define CONSTANTS41   0.45 
#define CONSTANTS42   0.25 
#define CONSTANTS43   0.15 
#define CONSTANTS44   0.92 
#define CONSTANTS45   0.09 
#define CONSTANTS46   0.25 
#define CONSTANTS47   0.15 
#define CONSTANTS48   1.0 
#define CONSTANTS49   4.0 
#define CONSTANTS50   2.5 
#define CONSTANTS51   0.1 
#define CONSTANTS52   1.0 
#define CONSTANTS53   5.0 
#define CONSTANTS54   350. 
#define CONSTANTS55   400. 
#define CONSTANTS56   500 
#define CONSTANTS57   20 

#define CONSTANTS59   0.08 
#define CONSTANTS60   0.000062 
#define CONSTANTS61   100. 
#define CONSTANTS62   0. 



#define CONSTANTS66   100. 
#define CONSTANTS67   0. 
#define CONSTANTS71   20.5 
#define CONSTANTS72   0. 
#define CONSTANTS73   0.002 
#define CONSTANTS74   0.18 
#define CONSTANTS75   0.000052 
#define CONSTANTS76   30. 
#define CONSTANTS77   0. 
#define CONSTANTS78   0.01 
#define CONSTANTS79   3.8 
#define CONSTANTS80   0.0017 
#define CONSTANTS81   30. 
#define CONSTANTS82   0. 
#define CONSTANTS83   0.05 
#define CONSTANTS84   0.25 
#define CONSTANTS85   0.0006 
#define CONSTANTS86   20.5 
#define CONSTANTS87   0. 


typedef struct {
realtype VOI;
//                1           2         3         4          5         6         7
realtype RSAT, RSCP, RSAR, RSVN, RSAS, CSAT, LSAT;
realtype ALGEBRIAC[34];
} *UserData;

/* Functions Called by the Solver */
static int f(realtype t, N_Vector y, N_Vector ydot, void *user_data);

/*
 *-------------------------------
 * Main Program
 *-------------------------------
 */
int main (int argc, char *argv[])
{
  realtype t, tout;
  N_Vector y;
  void *cvode_mem;
  int iout, i;
  char *str;
  FILE *output, *initial_conditions;

/* The measurement arrays */
int NOUT, someI;
int whichPar, parFold;
double parMult;

UserData data;
data = (UserData) malloc(sizeof *data); // now it is created.

// set up parameters.
/*
RSAT: systemic artery resistance. 		 CONSTANTS[63]
RSCP: systemic capillary bed resistance.  CONSTANTS69
RSAR: systemic arteriole bed resistance.   CONSTANTS[68]
RSVN: systemic vein resistance.		 CONSTANTS[70]
RSAS: systemic aortic sinus resistance.     CONSTANTS[58]
CSAT: systemic artery capacitance.  	CONSTANTS[64]
 LSAT: systemic artery compliance. 		CONSTANTS[65]

#define CONSTANTS58   0.003 
#define CONSTANTS63   0.05 
#define CONSTANTS64   1.6 
#define CONSTANTS65   0.0017 
#define CONSTANTS68   0.5 
#define CONSTANTS69   0.52 
#define CONSTANTS70   0.075 
*/

// baseline values.
data->RSAT =  0.05;
data->RSCP = 0.52;
data->RSAR = 0.5;
data->RSVN = 0.075;
data->RSAS = 0.003;
data->CSAT = 1.6;
data->LSAT = 0.0017;

if(argc<3){printf("I need two inputs. argv1 as the multiplier, or fraction of multiplier; argv2 as parameter choice (1 to 7 inclusive.)\n"); exit(0); }

parFold = atoi(argv[1]);
whichPar = atoi(argv[2]);

parMult = ( (double)(parFold)/2.0 ); // each parFold represents half fold multiplier.

if(whichPar == 1) data->RSAT =  parMult   * 0.05;
if(whichPar == 2) data->RSCP = parMult   * 0.52;
if(whichPar == 3) data->RSAR = parMult   * 0.5;
if(whichPar == 4) data->RSVN = parMult   * 0.075;
if(whichPar == 5) data->RSAS = parMult   * 0.003;
if(whichPar == 6) data->CSAT = parMult   * 1.6;
if(whichPar == 7) data->LSAT = parMult    * 0.0017;

/* Start the automation loops here */
y 				= NULL;
cvode_mem 		= NULL;
NOUT 			= (int)(((num_beats+1)*1.0)/dt);
/* Create serial vector of length NEQ for I.C. and abstol */
  y 				= N_VNew_Serial(NEQ);
 /* Initialize y. The Y1, Y2,... are defined in the header. */
   //---------------------------------------------------------------------------
   // State variables: initial conditions.
   //---------------------------------------------------------------------------
// initial conditions.
   Ith(y, 1) =   CONSTANTS61;
   Ith(y, 2) =   CONSTANTS76;
   Ith(y, 3) =   CONSTANTS3;
   Ith(y, 4) =   CONSTANTS7;
   Ith(y, 5) =   CONSTANTS32;
   Ith(y, 6) =   CONSTANTS36;
   Ith(y, 7) =   CONSTANTS66;
   Ith(y, 8) =   CONSTANTS62;
   Ith(y, 9) =   CONSTANTS67;
   Ith(y, 10) =   CONSTANTS72;
   Ith(y, 11) =   CONSTANTS81;
   Ith(y, 12) =   CONSTANTS77;
   Ith(y, 13) =   CONSTANTS82;
   Ith(y, 14) =   CONSTANTS87;

  cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON);
  CVodeInit(cvode_mem, f, 0.0, y);
  CVodeSStolerances(cvode_mem, 10e-6, 10e-6);
  CVDense(cvode_mem, NEQ);
  CVodeSetMaxStep(cvode_mem,dt);

iout = 0;  tout = dt;

str = malloc(32*sizeof(char));
sprintf(str,"output_%d_%d.dat", whichPar, parFold);
output = fopen(str,"w+");
free(str);
for(iout=0; iout<NOUT; iout++){
	data->VOI = tout;
	if(iout%100==0 && tout > 90.0){ 
		fprintf(output, "%f ", tout);
		for(i = 1; i <= NEQ; i++)    fprintf(output,"%f ",Ith(y, i) );
		for(i = 0; i < 34; i++)        fprintf(output,"%f ",data->ALGEBRIAC[i] );		
		fprintf(output,"\n");
	}	
	CVodeSetUserData(cvode_mem, data); // use when data is changing/user set.
	CVode(cvode_mem, tout, y, &t, CV_NORMAL);
      tout += dt;
} /* end of time loop */

  fclose(output);
      
  N_VDestroy_Serial(y);
  CVodeFree(&cvode_mem);
  free(data);
  return(0);

} // end of main.

/***************************************************************************************************/
/***************************************************************************************************/

static int f(realtype t, N_Vector y, N_Vector ydot, void *user_data)
{
 realtype Y[NEQ];
 realtype dY[NEQ];
 realtype RATES[NEQ];
 realtype STATES[NEQ];
 realtype ALGEBRAIC[88];
 realtype VOI;
 int i;

 realtype CONSTANTS58, CONSTANTS63, CONSTANTS64, CONSTANTS65, CONSTANTS68, CONSTANTS69, CONSTANTS70;
 
  UserData data;
 data = (UserData) user_data;
 
 VOI = data->VOI;

 CONSTANTS63 = data->RSAT; // = 0.05;
CONSTANTS69 = data->RSCP; // = 0.52;
CONSTANTS68 = data->RSAR; // = 0.5;
CONSTANTS70 = data->RSVN; // = 0.075;
CONSTANTS58 = data->RSAS; // = 0.003;
CONSTANTS64 = data->CSAT; // = 1.6;
CONSTANTS65 = data->LSAT; // = 0.0017;

  for(i=0;i<NEQ;i++) Y[i] = Ith(y,i+1);
  for(i=0;i<NEQ;i++) STATES[i] = Y[i]; // is this needed?
/***************************************************************************************************/

// calculate the rates.
RATES[7] = ((STATES[0] - STATES[6]) -  CONSTANTS58*STATES[7])/CONSTANTS60;
RATES[6] = (STATES[7] - STATES[8])/CONSTANTS64;
RATES[11] = ((STATES[1] - STATES[10]) -  CONSTANTS73*STATES[11])/CONSTANTS75;
RATES[10] = (STATES[11] - STATES[12])/CONSTANTS79;
ALGEBRAIC[0] = VOI -  CONSTANTS10*floor(VOI/CONSTANTS10);
ALGEBRAIC[2] = (ALGEBRAIC[0]>=0.00000&&ALGEBRAIC[0]<= CONSTANTS11*CONSTANTS10 ? 1.00000 - cos(( 3.14159*ALGEBRAIC[0])/( CONSTANTS11*CONSTANTS10)) : ALGEBRAIC[0]> CONSTANTS11*CONSTANTS10&&ALGEBRAIC[0]<= CONSTANTS12*CONSTANTS10 ? 1.00000+cos(( 3.14159*(ALGEBRAIC[0] -  CONSTANTS11*CONSTANTS10))/( (CONSTANTS12 - CONSTANTS11)*CONSTANTS10)) : ALGEBRAIC[0]> CONSTANTS12 * CONSTANTS10 &&ALGEBRAIC[0]<CONSTANTS10 ? 0.00000 : 0.0/0.0);
ALGEBRAIC[4] = CONSTANTS9 + ( ALGEBRAIC[2]*(CONSTANTS8 - CONSTANTS9 ))/2.00000;
ALGEBRAIC[6] = CONSTANTS1 + ALGEBRAIC[4]*(STATES[2] - CONSTANTS2);
ALGEBRAIC[8] = (ALGEBRAIC[6]>=STATES[0] ? 1.00000 : ALGEBRAIC[6]<STATES[0] ? 0.00000 : 0.0/0.0);
ALGEBRAIC[10] = (ALGEBRAIC[6]>=STATES[0] ?  CONSTANTS0 * ALGEBRAIC[8]*pow(fabs(ALGEBRAIC[6] - STATES[0]), 0.500000) : ALGEBRAIC[6]<STATES[0] ?  -1.00000*CONSTANTS0 * ALGEBRAIC[8]*pow(fabs(STATES[0] - ALGEBRAIC[6]), 0.500000) : 0.0/0.0);
RATES[0] = (ALGEBRAIC[10] - STATES[7])/CONSTANTS59;
ALGEBRAIC[1] = VOI -  CONSTANTS39 * floor(VOI/CONSTANTS39);
ALGEBRAIC[3] = (ALGEBRAIC[1]>=0.00000&&ALGEBRAIC[1]<= CONSTANTS40 * CONSTANTS39 ? 1.00000 - cos(( 3.14159*ALGEBRAIC[1])/( CONSTANTS40  * CONSTANTS39 )) : ALGEBRAIC[1]> CONSTANTS40 * CONSTANTS39 &&ALGEBRAIC[1]<= CONSTANTS41 * CONSTANTS39  ? 1.00000+cos(( 3.14159*(ALGEBRAIC[1] -  CONSTANTS40 * CONSTANTS39 ))/( (CONSTANTS41  - CONSTANTS40 )*CONSTANTS39 )) : ALGEBRAIC[1]> CONSTANTS41 * CONSTANTS39 &&ALGEBRAIC[1]<CONSTANTS39  ? 0.00000 : 0.0/0.0);
ALGEBRAIC[5] = CONSTANTS38 + ( ALGEBRAIC[3]*(CONSTANTS37 - CONSTANTS38 ))/2.00000;
ALGEBRAIC[7] = CONSTANTS30 + ALGEBRAIC[5]*(STATES[4] - CONSTANTS31 );
ALGEBRAIC[9] = (ALGEBRAIC[7]>=STATES[1] ? 1.00000 : ALGEBRAIC[7]<STATES[1] ? 0.00000 : 0.0/0.0);
ALGEBRAIC[11] = (ALGEBRAIC[7]>=STATES[1] ?  CONSTANTS29 * ALGEBRAIC[9]*pow(fabs(ALGEBRAIC[7] - STATES[1]), 0.500000) : ALGEBRAIC[7]<STATES[1] ?  -1.00000*CONSTANTS29 * ALGEBRAIC[9]*pow(fabs(STATES[1] - ALGEBRAIC[7]), 0.500000) : 0.0/0.0);
RATES[1] = (ALGEBRAIC[11] - STATES[11])/CONSTANTS74 ;
ALGEBRAIC[12] = VOI -  CONSTANTS10 * floor(VOI/CONSTANTS10 );


// this seems to be something to do with the P wave in the left atrium.
ALGEBRAIC[14] = (ALGEBRAIC[12]>=0.00000&&ALGEBRAIC[12]<= (CONSTANTS15 + CONSTANTS16 )*CONSTANTS10 - CONSTANTS10  ? 1.00000 - cos(( 2.00000*3.14159*((ALGEBRAIC[12] -  CONSTANTS15 * CONSTANTS10 )+CONSTANTS10 ))/( CONSTANTS16 * CONSTANTS10 )) : ALGEBRAIC[12]> (CONSTANTS15+CONSTANTS16 )*CONSTANTS10 - CONSTANTS10 &&ALGEBRAIC[12]<= CONSTANTS15 * CONSTANTS10  ? 0.00000 : ALGEBRAIC[12]> CONSTANTS15 * CONSTANTS10 &&ALGEBRAIC[12]<=CONSTANTS10 ? 1.00000 - cos(( 2.00000*3.14159*(ALGEBRAIC[12] -  CONSTANTS15 * CONSTANTS10 ))/( CONSTANTS16 * CONSTANTS10 )) : 0.0/0.0);



ALGEBRAIC[16] = CONSTANTS14 + ( ALGEBRAIC[14]*(CONSTANTS13 - CONSTANTS14))/2.00000;   // elat?


ALGEBRAIC[18] = CONSTANTS5 + ALGEBRAIC[16]*(STATES[3] - CONSTANTS6 ); // left atrial pressure?


ALGEBRAIC[20] = (ALGEBRAIC[18]>=ALGEBRAIC[6] ? 1.00000 : ALGEBRAIC[18]<ALGEBRAIC[6] ? 0.00000 : 0.0/0.0);
ALGEBRAIC[22] = (ALGEBRAIC[18]>=ALGEBRAIC[6] ?  CONSTANTS4 *ALGEBRAIC[20]*pow(fabs(ALGEBRAIC[18] - ALGEBRAIC[6]), 0.500000) : ALGEBRAIC[18]<ALGEBRAIC[6] ?  -1.00000*CONSTANTS4 *ALGEBRAIC[20]*pow(fabs(ALGEBRAIC[6] - ALGEBRAIC[18]), 0.500000) : 0.0/0.0);
RATES[2] = ALGEBRAIC[22] - ALGEBRAIC[10];
ALGEBRAIC[13] = VOI -  CONSTANTS39 * floor(VOI/CONSTANTS39 );
ALGEBRAIC[15] = (ALGEBRAIC[13]>=0.00000&&ALGEBRAIC[13]<= (CONSTANTS44 + CONSTANTS45 )*CONSTANTS39 - CONSTANTS39 ? 1.00000 - cos(( 2.00000*3.14159*((ALGEBRAIC[13] -  CONSTANTS44 * CONSTANTS39 )+CONSTANTS39 ))/( CONSTANTS45 * CONSTANTS39 )) : ALGEBRAIC[13]> (CONSTANTS44+CONSTANTS45 )*CONSTANTS39 - CONSTANTS39 && ALGEBRAIC[13]<= CONSTANTS44 * CONSTANTS39 ? 0.00000 : ALGEBRAIC[13]> CONSTANTS44 *CONSTANTS39 &&ALGEBRAIC[13]<=CONSTANTS39 ? 1.00000 - cos(( 2.00000*3.14159*(ALGEBRAIC[13] -  CONSTANTS44 * CONSTANTS39 ))/( CONSTANTS45 * CONSTANTS39 )) : 0.0/0.0);
ALGEBRAIC[17] = CONSTANTS43 + ( ALGEBRAIC[15]*(CONSTANTS42  - CONSTANTS43 ))/2.00000;
ALGEBRAIC[19] = CONSTANTS34 + ALGEBRAIC[17]*(STATES[5] - CONSTANTS35 );
ALGEBRAIC[21] = (ALGEBRAIC[19]>=ALGEBRAIC[7] ? 1.00000 : ALGEBRAIC[19]<ALGEBRAIC[7] ? 0.00000 : 0.0/0.0);
ALGEBRAIC[23] = (ALGEBRAIC[19]>=ALGEBRAIC[7] ?  CONSTANTS33 * ALGEBRAIC[21]*pow(fabs(ALGEBRAIC[19] - ALGEBRAIC[7]), 0.500000) : ALGEBRAIC[19]<ALGEBRAIC[7] ?  -1.00000*CONSTANTS33 * ALGEBRAIC[21]*pow(fabs(ALGEBRAIC[7] - ALGEBRAIC[19]), 0.500000) : 0.0/0.0);
RATES[4] = ALGEBRAIC[23] - ALGEBRAIC[11];


ALGEBRAIC[30] = (STATES[13] - ALGEBRAIC[18])/CONSTANTS85;
RATES[3] = ALGEBRAIC[30] - ALGEBRAIC[22]; // looks like LV volume.


ALGEBRAIC[31] = (STATES[9] - ALGEBRAIC[19])/CONSTANTS70;
RATES[5] = ALGEBRAIC[31] - ALGEBRAIC[23];
ALGEBRAIC[25] = STATES[8];
ALGEBRAIC[28] = STATES[9]+ CONSTANTS69 * ALGEBRAIC[25];
ALGEBRAIC[32] = ALGEBRAIC[28]+ CONSTANTS68 * STATES[8];
RATES[8] = ((STATES[6] - ALGEBRAIC[32]) -  CONSTANTS63 * STATES[8])/CONSTANTS65;
ALGEBRAIC[27] = ALGEBRAIC[25];
RATES[9] = (ALGEBRAIC[27] - ALGEBRAIC[31])/CONSTANTS71;
ALGEBRAIC[24] = STATES[12];
ALGEBRAIC[29] = STATES[13]+ CONSTANTS84 * ALGEBRAIC[24];
ALGEBRAIC[33] = ALGEBRAIC[29]+ CONSTANTS83 * STATES[12];
RATES[12] = ((STATES[10] - ALGEBRAIC[33]) -  CONSTANTS78 * STATES[12])/CONSTANTS80;
ALGEBRAIC[26] = ALGEBRAIC[24];
RATES[13] = (ALGEBRAIC[26] - ALGEBRAIC[30])/CONSTANTS86;

// algebriac formulas.
ALGEBRAIC[0] = VOI -  CONSTANTS10 * floor(VOI/CONSTANTS10 );
ALGEBRAIC[2] = (ALGEBRAIC[0]>=0.00000&&ALGEBRAIC[0]<= CONSTANTS11 * CONSTANTS10 ? 1.00000 - cos(( 3.14159*ALGEBRAIC[0])/( CONSTANTS11 * CONSTANTS10 )) : ALGEBRAIC[0]> CONSTANTS11 * CONSTANTS10 &&ALGEBRAIC[0]<= CONSTANTS12 * CONSTANTS10 ? 1.00000+cos(( 3.14159*(ALGEBRAIC[0] -  CONSTANTS11 * CONSTANTS10 ))/( (CONSTANTS12 - CONSTANTS11 )*CONSTANTS10)) : ALGEBRAIC[0]> CONSTANTS12 * CONSTANTS10 &&ALGEBRAIC[0]<CONSTANTS10 ? 0.00000 : 0.0/0.0);
ALGEBRAIC[4] = CONSTANTS9 + ( ALGEBRAIC[2]*(CONSTANTS8 - CONSTANTS9))/2.00000;
ALGEBRAIC[6] = CONSTANTS1 + ALGEBRAIC[4]*(STATES[2] - CONSTANTS2 ); // is this LV pressure? It looks a bit like elastance?



ALGEBRAIC[8] = (ALGEBRAIC[6]>=STATES[0] ? 1.00000 : ALGEBRAIC[6]<STATES[0] ? 0.00000 : 0.0/0.0);

// Algebraic 10 is the flow from ventricle into the aortic sinus, eq. 13 in the main paper of 2006.
// this may allow us to investigate regurgitation.
// these formulas for ALG8 and ALG10 occur twice in this RHS.
// the radius of aortic root goes in the detailed model of ALG10 opening.
ALGEBRAIC[10] = (ALGEBRAIC[6]>=STATES[0] ?  CONSTANTS0 * ALGEBRAIC[8]*pow(fabs(ALGEBRAIC[6] - STATES[0]), 0.500000) : ALGEBRAIC[6]<STATES[0] ?  -1.00000*CONSTANTS0 * ALGEBRAIC[8]*pow(fabs(STATES[0] - ALGEBRAIC[6]), 0.500000) : 0.0/0.0);



ALGEBRAIC[1] = VOI -  CONSTANTS39 * floor(VOI/CONSTANTS39 );
ALGEBRAIC[3] = (ALGEBRAIC[1]>=0.00000&&ALGEBRAIC[1]<= CONSTANTS40 * CONSTANTS39 ? 1.00000 - cos(( 3.14159*ALGEBRAIC[1])/( CONSTANTS40 * CONSTANTS39 )) : ALGEBRAIC[1]> CONSTANTS40 * CONSTANTS39 &&ALGEBRAIC[1]<= CONSTANTS41 * CONSTANTS39 ? 1.00000+cos(( 3.14159*(ALGEBRAIC[1] -  CONSTANTS40 * CONSTANTS39 ))/( (CONSTANTS41 - CONSTANTS40 )*CONSTANTS39 )) : ALGEBRAIC[1]> CONSTANTS41*CONSTANTS39&&ALGEBRAIC[1]<CONSTANTS39 ? 0.00000 : 0.0/0.0);
ALGEBRAIC[5] = CONSTANTS38+( ALGEBRAIC[3]*(CONSTANTS37 - CONSTANTS38 ))/2.00000;
ALGEBRAIC[7] = CONSTANTS30 + ALGEBRAIC[5]*(STATES[4] - CONSTANTS31 );
ALGEBRAIC[9] = (ALGEBRAIC[7]>=STATES[1] ? 1.00000 : ALGEBRAIC[7]<STATES[1] ? 0.00000 : 0.0/0.0);


// whats this?
ALGEBRAIC[11] = (ALGEBRAIC[7]>=STATES[1] ?  CONSTANTS29 * ALGEBRAIC[9]*pow(fabs(ALGEBRAIC[7] - STATES[1]), 0.500000) : ALGEBRAIC[7]<STATES[1] ?  -1.00000*CONSTANTS29 * ALGEBRAIC[9]*pow(fabs(STATES[1] - ALGEBRAIC[7]), 0.500000) : 0.0/0.0);


ALGEBRAIC[12] = VOI -  CONSTANTS10 * floor(VOI/CONSTANTS10 );
ALGEBRAIC[14] = (ALGEBRAIC[12]>=0.00000&&ALGEBRAIC[12]<= (CONSTANTS15 + CONSTANTS16 )*CONSTANTS10 - CONSTANTS10 ? 1.00000 - cos(( 2.00000*3.14159*((ALGEBRAIC[12] -  CONSTANTS15 * CONSTANTS10 )+CONSTANTS10 ))/( CONSTANTS16 * CONSTANTS10 )) : ALGEBRAIC[12]> (CONSTANTS15+CONSTANTS16 )*CONSTANTS10 - CONSTANTS10 &&ALGEBRAIC[12]<= CONSTANTS15 * CONSTANTS10 ? 0.00000 : ALGEBRAIC[12]> CONSTANTS15 * CONSTANTS10 &&ALGEBRAIC[12]<=CONSTANTS10 ? 1.00000 - cos(( 2.00000*3.14159*(ALGEBRAIC[12] -  CONSTANTS15 * CONSTANTS10 ))/( CONSTANTS16 * CONSTANTS10 )) : 0.0/0.0);
ALGEBRAIC[16] = CONSTANTS14 + ( ALGEBRAIC[14]*(CONSTANTS13 - CONSTANTS14 ))/2.00000;
ALGEBRAIC[18] = CONSTANTS5 + ALGEBRAIC[16]*(STATES[3] - CONSTANTS6);
ALGEBRAIC[20] = (ALGEBRAIC[18]>=ALGEBRAIC[6] ? 1.00000 : ALGEBRAIC[18]<ALGEBRAIC[6] ? 0.00000 : 0.0/0.0);
ALGEBRAIC[22] = (ALGEBRAIC[18]>=ALGEBRAIC[6] ?  CONSTANTS4 * ALGEBRAIC[20]*pow(fabs(ALGEBRAIC[18] - ALGEBRAIC[6]), 0.500000) : ALGEBRAIC[18]<ALGEBRAIC[6] ?  -1.00000*CONSTANTS4 * ALGEBRAIC[20]*pow(fabs(ALGEBRAIC[6] - ALGEBRAIC[18]), 0.500000) : 0.0/0.0);
ALGEBRAIC[13] = VOI -  CONSTANTS39 * floor(VOI/CONSTANTS39 );
ALGEBRAIC[15] = (ALGEBRAIC[13]>=0.00000&&ALGEBRAIC[13]<= (CONSTANTS44 + CONSTANTS45 )*CONSTANTS39 - CONSTANTS39 ? 1.00000 - cos(( 2.00000*3.14159*((ALGEBRAIC[13] -  CONSTANTS44 * CONSTANTS39 )+CONSTANTS39 ))/( CONSTANTS45 * CONSTANTS39 )) : ALGEBRAIC[13]> (CONSTANTS44+CONSTANTS45 )*CONSTANTS39 - CONSTANTS39 && ALGEBRAIC[13]<= CONSTANTS44 * CONSTANTS39 ? 0.00000 : ALGEBRAIC[13]> CONSTANTS44 * CONSTANTS39 &&ALGEBRAIC[13]<=CONSTANTS39 ? 1.00000 - cos(( 2.00000*3.14159*(ALGEBRAIC[13] -  CONSTANTS44 * CONSTANTS39 ))/( CONSTANTS45 * CONSTANTS39 )) : 0.0/0.0);
ALGEBRAIC[17] = CONSTANTS43 + ( ALGEBRAIC[15]*(CONSTANTS42 - CONSTANTS43 ))/2.00000;
ALGEBRAIC[19] = CONSTANTS34 + ALGEBRAIC[17]*(STATES[5] - CONSTANTS35);
ALGEBRAIC[21] = (ALGEBRAIC[19]>=ALGEBRAIC[7] ? 1.00000 : ALGEBRAIC[19]<ALGEBRAIC[7] ? 0.00000 : 0.0/0.0);
ALGEBRAIC[23] = (ALGEBRAIC[19]>=ALGEBRAIC[7] ?  CONSTANTS33 * ALGEBRAIC[21]*pow(fabs(ALGEBRAIC[19] - ALGEBRAIC[7]), 0.500000) : ALGEBRAIC[19]<ALGEBRAIC[7] ?  -1.00000*CONSTANTS33 * ALGEBRAIC[21]*pow(fabs(ALGEBRAIC[7] - ALGEBRAIC[19]), 0.500000) : 0.0/0.0);
ALGEBRAIC[30] = (STATES[13] - ALGEBRAIC[18])/CONSTANTS85;
ALGEBRAIC[31] = (STATES[9] - ALGEBRAIC[19])/CONSTANTS70;
ALGEBRAIC[25] = STATES[8];
ALGEBRAIC[28] = STATES[9]+ CONSTANTS69 * ALGEBRAIC[25];
ALGEBRAIC[32] = ALGEBRAIC[28]+ CONSTANTS68 * STATES[8];
ALGEBRAIC[27] = ALGEBRAIC[25];
ALGEBRAIC[24] = STATES[12];
ALGEBRAIC[29] = STATES[13]+ CONSTANTS84 * ALGEBRAIC[24];
ALGEBRAIC[33] = ALGEBRAIC[29]+ CONSTANTS83 * STATES[12];
ALGEBRAIC[26] = ALGEBRAIC[24];

/***************************************************************************************************/
for(i=0;i<NEQ;i++)   dY[i] = RATES[i];
for(i=0;i<NEQ;i++)   Ith(ydot,i+1) = dY[i];

for(i=0; i < 34; i++) data->ALGEBRIAC[i] = ALGEBRAIC[i];

 return(0);
} // end of RHS f function.

/***************************************************************************************************/
/***************************************************************************************************/

