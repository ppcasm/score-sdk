#ifdef mp3drv

#ifndef __MP3_H__
#define __MP3_H__

/* MP3 decoder definitions */
#define MP3_BITSTREAM_BUFFER_SIZE   (4096)  // size in bytes
#define MP3_MAX_FRAME_SAMPLES       (1152)  // max samples per frame
#define MP3_DECODER_WORK_SPACE      (18432) // size in bytes
#define MP3_ANALYZER_WORK_SPACE     (128)   // size in bytes
#define PCM_FIFO_BYTE_SIZE          (1152*2/*ch*/*2/*bytes*/) // size in bytes

/* MP3 encoder definitions */
#define MP3_MAX_ENCODED_BYTES       2048 // Encoder output buffer size
#define MP3_PCM_BUFFER_SIZE         1152 // Number of samples per MP3 frame

/*
 * Decoder interface
 */
typedef enum
{
  MP3_OK            =  0,
  MP3_WAIT_INPUT    = -1,
  MP3_HEADER_SEARCH = -2,
  MP3_HEADER_RESYNC = -3,
  MP3_SYNTAX_ERROR  = -4,
  MP3_INVALID_ARG   = -5
}   MP3_ERROR_CODE;

int             mp3_get_bitrate(void * decoder); // returns bitrate in kbps.
int             mp3_get_sampling_rate(void * decoder); // returns sampling rate in Hz.
int             mp3_get_frame_count(void * decoder);
int             mp3_get_channel_number(void * decoder);

int             mp3_decoder_init(void * decoder, unsigned char * mp3bsbuf, int internal_resource);
int             mp3_decoder_run(void * decoder, int wi, short * pcm_output);
int             mp3_decoder_read_index(void * decoder);
int             mp3_decoder_set_file_end(void * decoder);
int             mp3_errno(void * decoder);
const char *    mp3_version_string(void);

/*
 * Analyzer interface
 */
#define NO_VBR_HEADER   0
#define XING_HEADER     1
#define VBRI_HEADER     2

typedef struct mp3_frame_info_s
{
  unsigned      mp3_header_found;   // check it to see if any MPEG audio header found
  unsigned      version;            // 0:MPEG 1, 1:MPEG 2 LSF, 2:MPEG 2.5
  unsigned      layer;              // 1~3
  unsigned      bit_rate;           // in kbps
  unsigned      sampling_rate;      // in Hz
  unsigned      channel_number;     // 1 or 2

  unsigned      vbr;                // 0: CBR, 1: VBR
  unsigned      vbr_header_present; // NO_VBR_HEADER, XING_HEADER or VBRI_HEADER
  unsigned      total_mp3_bytes;
  unsigned      total_frame_number;
  unsigned      quality;            // 0(best) ~ 100(worst)
  unsigned      vbri_toc_entries;           // number of TOC entries in VBRI header
  unsigned      vbri_toc_scale;             // scale of TOC entries in VBRI header
  unsigned      vbri_toc_entry_size;        // size of a TOC entry in VBRI header
  unsigned      vbri_frames_per_toc_entry;  // frames per TOC entry in VBRI header
  unsigned      TOC_present;
  union
  {
    unsigned char   byte[512];      // Xing TOC uses first 100 bytes.
    unsigned short  halfword[256];
    unsigned        word[128];
  } TOC;
} mp3_frame_info_t;

int mp3_analyzer_init(void * analyzer, unsigned char * p_bs, mp3_frame_info_t * p_mp3fr_info);
int mp3_analyzer_read_index(void * analyzer);
int mp3_analyzer_run(void * analyzer, int wp);
int mp3_analyzer_stop(void * analyzer);

/*
 * Encoder interface
 */
int mp3_encoder_init(int bitrate, int Fs, int ch_num);
int mp3_encoder_run(unsigned char output_ptr[MP3_MAX_ENCODED_BYTES], const short pcm_in[1152*2]);

int mp3_encoder_frame_size(void); // return number of samples per frame

#endif //!__MP3_H__

//MP3_Status

#define	D_MP3_Play		0x0001

#define	D_MP3_Pause		0x0002

#define	D_MP3_Repeat	0x0004

#define D_MP3_Speed		0x0008

#define D_MP3_Data_End	0x0010

#define D_MP3_Encode	0x0020

#define	D_MP3_Buf_Empty	0x0040


#define	D_MP3_PCM_Empty	0x0080

//MP3_Output_Type

#define	Stereo		0x0001

#define	Left_Only	0x0002

#define Right_Only	0x0004

extern unsigned char *L_MP3Files;
extern unsigned short *Address;

#endif

