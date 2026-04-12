#ifdef mp3drv

void MP3_Service_Loop_ISR(void);
void Init_MP3(void);
void Play_MP3(unsigned int MP3_Addr, unsigned int Length);
unsigned int Get_MP3_Status(void);
void Stop_MP3(void);
void Pause_MP3(void);
void Resume_MP3(void);
void Repeat_ON_MP3(void);
void Repeat_OFF_MP3(void);
void MP3_Output_Stereo(void);
void MP3_Output_Left_Only(void);
void MP3_Output_Right_Only(void);
void MP3_Service_Loop(void);
 
#endif

