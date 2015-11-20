#define	S_FUNCTION_NAME		thcal	/*�r�t�@���N�V�������̒�`*/
#define	S_FUNCTION_LEVEL	2		/*�t�@���N�V�������x��??�Q*/


#include "simstruc.h"
#include "math.h"
//#include "size.h"

double	vt_in;
double	vt_buf;
double	vt_out;

double	vxg_in;
double sp_ini;


int first=0;
int counter=0;
double aux1 =0;
double aux2 =0;


static	void	mdlInitializeSizes( SimStruct *S )	/*�T�C�Y?�������?�*/
{
	long	board_base;								/*�{?[�h�A�h���X�p��?�*/

	ssSetNumSFcnParams( S, 0 );						/*�p���??[�^��?���?ݒ�	*/
	ssSetNumContStates( S, 0 );						/**/
	ssSetNumDiscStates( S, 0 );						/**/
	ssSetNumInputPorts( S, 1 );						/*����?���?ݒ�	*/
	ssSetInputPortWidth( S, 0,  2 );				//�R�ڂ̈�?���Matlab��Mux��ʂ��ē��͂�����?�
													/*�Q�Ԗڂ̓��̓f?[�^�̕?���R�v�f�ɂ�?ݒ�*/
	ssSetInputPortDirectFeedThrough( S, 0, 1 );		/*�_�C���N�g�t�B?[���h�X��?[��?ݒ�*/
	ssSetNumOutputPorts( S, 1 );					/*?o��?���?ݒ�*/
	ssSetOutputPortWidth( S, 0, 1  );				//�R�ڂ̈�?���Matlab?��?o�͂�����?���?�
													/*�O�Ԗڂ�?o�̓f?[�^�̕?��?ݒ�*/
	ssSetNumSampleTimes( S, 1 );					/*�T���v���^�C��?���?ݒ�*/
	ssSetNumRWork( S, 0 );				/**/
	ssSetNumIWork( S, 0 );				/**/
	ssSetNumPWork( S, 0 );				/**/
	ssSetNumModes( S, 0 );				/**/
	ssSetNumNonsampledZCs( S, 0 );		/**/
	ssSetOptions(S,	0);					/**/

}

static	void	mdlInitializeSampleTimes( SimStruct *S )/*�T���v���^�C��?�������?�*/
{
	ssSetSampleTime( S, 0, INHERITED_SAMPLE_TIME );						/*�T���v���^�C����?ݒ�?i�P�O�O�?�����Ɏ�?s����?j*/
	ssSetOffsetTime( S, 0, 0.0 );						/*�I�t�Z�b�g�^�C����?ݒ�*/
}






#define	MDL_INITIALIZE_CONDITIONS				/*��`?F������`���Ă��Ȃ�������?iundef?j���L�𖳌�*/
#if	defined( MDL_INITIALIZE_CONDITIONS )		/*������?A��`���Ă�������L���ɂ���*/
static	void	mdlInitializeConditions( SimStruct *S )	
{				/*?���?ݒ��?�?F�T���v�����O�������J�n�����O��?���?ݒ�*/

}
#endif							/*������?A��`���Ă�������L���ɂ���	*/

#define	MDL_START								/*��`?F������`���Ă��Ȃ�������?iundef?j���L�𖳌�*/
#if	defined( MDL_START )						/*������?A��`���Ă�������L���ɂ���*/
	static	void	mdlStart( SimStruct *S )	/*�J�n����?�*/
	{											/*?���?ݒ��?�?F�T���v�����O�������J�n�����O��?���?ݒ�*/

	}
#endif							/*������?A��`���Ă�������L���ɂ���*/

static	void	mdlOutputs( SimStruct *S, int_T tid )	/*?o�͊�?�*/
{
	InputRealPtrsType	uPtrs =	ssGetInputPortRealSignalPtrs( S, 0 );
	real_T			*y = ssGetOutputPortRealSignal( S, 0 );	
	

	vt_in = *uPtrs[0];
	vxg_in = *uPtrs[1];
    
 if (vxg_in == 1)
 {   
    if (first == 0)
    {
        sp_ini = 4.0; // vt_in;   
        first = 1;
    }
    
    if (counter < 3001)
    {
        vt_out = sp_ini; 
        counter = counter + 1;
    }    
    if (counter > 3000 && counter < 3501)
    {
        vt_out = sp_ini-1*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    if (counter > 3500 && counter < 4501)
    {
        vt_out = sp_ini-1; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 4500 && counter < 5001)
    {
        vt_out = sp_ini-1+3*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
    
    if (counter > 5000 && counter < 6001)
    {
        vt_out = sp_ini+2; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 6000 && counter < 6501)
    {
        vt_out = sp_ini+2-4*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    if (counter > 6500 && counter < 8501)
    {
        vt_out = sp_ini-2; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 8500 && counter < 9001)
    {
        vt_out = sp_ini-2+2*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
    
    if (counter > 9000 && counter < 10001)
    {
        vt_out = sp_ini; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    } 
    
    if (counter > 10000 && counter < 10501)
    {
        vt_out = sp_ini+1*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    if (counter > 10500 && counter < 11501)
    {
        vt_out = sp_ini+1; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 11500 && counter < 12001)
    {
        vt_out = sp_ini+1-2*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
       
    if (counter > 12000 && counter < 13001)
    {
        vt_out = sp_ini-1; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    } 
    
    if (counter > 13000 && counter < 13501)
    {
        vt_out = sp_ini-1-1.5*(aux1/500.0); 
        counter = counter + 1;
        aux1=aux1+1;
    }     
    
    
    if (counter > 13500 && counter < 14501)
    {
        vt_out = sp_ini-2.5; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
    
    if (counter > 14500 && counter < 15001)
    {
        vt_out = sp_ini-2.5-1.5*(aux2/500.0); 
        counter = counter + 1;
        aux2=aux2+1;
    }   
    
    if (counter > 15000)
    {
        vt_out = sp_ini-4; 
        counter = counter + 1;
        aux1=0;
        aux2=0;
    }    
 }
 if (vxg_in == 0)
 {   
     counter = 0;
     aux1 = 0;
     aux2 = 0;
 }
     
    
    

	y[0] = vt_out;
	


}

#undef	MDL_UPDATE						/*��`*/
#if	defined( MDL_UPDATE )					/*������?A��`���Ă�������L���ɂ���*/
	static	void	mdlUpdate( SimStruct *S, int_T tid )	/*?X?V��?�*/
	{
	}
#endif								/*������?A��`���Ă�������L���ɂ���*/



#undef	MDL_DERIVATIVES						/**/
#if	defined( MDL_DERIVATIVES )				/*������?A��`���Ă�������L���ɂ���*/
	static	void	mdlDerivatives( SimStruct *S )		/*�����p��?�*/
	{
	}
#endif								/*������?A��`���Ă�������L���ɂ���*/



static	void	mdlTerminate( SimStruct *S )			/*?I�[��?�*/
{
}

#ifdef	MATLAB_MEX_FILE						/*�r�h�l�t�k�h�m�j���g�p����?�?���?A	*/
	#include	"simulink.c"				/*�C���N��?[�h����			*/
#else								/*�`�����?���?�����g�p����?�?���?A	*/
	#include	"cg_sfun.h"				/*�C���N��?[�h����			*/
#endif
