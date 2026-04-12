#ifndef __HYPERSCAN_H__
#define __HYPERSCAN_H__

#ifdef __cplusplus
extern "C" {
#endif

// Used to control the Hyperscan LEDs
#define HS_LEDS(value) (*P_CSI_GPIO_SETUP = (0x1FFE0000+(value<<5)))

// Used for iso_lseek
#define ISO_SEEK_SET 0
#define ISO_SEEK_CUR 1
#define ISO_SEEK_END 2

/**************************************************************************
 *               H Y P E R S C A N  O S  C A L L B A C K S                *
 **************************************************************************/

/* Call the ISO init routine at 0xA0000890, then restore $gp (r28) afterward
   (no return) */
#define iso_init()                        \
    ({                                    \
        /* Call iso_init from cb table */ \
        ((void (*)(void))0xA0000890)();   \
        /* Restore $gp (r28) */           \
        __asm__ volatile("la r28, _gp");  \
    })

/* Call the ISO open routine at 0xA000089C(char *), save its int return,
   then restore $gp (r28) before yielding return. */
#define iso_open(path)                                    \
    ({                                                    \
        /* Call iso_open from cb table */                 \
        int __ret = ((int (*)(char *))0xA000089C)(path);  \
        /* Restore $gp (r28) */                           \
        __asm__ volatile("la   r28, _gp");                \
        /* Yield the return value */                      \
        __ret;                                            \
    })

/* Call the ISO read routine at 0xA00008A8(int, void*, unsigned int), save its int return,
   then restore $gp (r28) before yielding return. */
#define iso_read(fd, buf, len)                                                      \
    ({                                                                              \
        /* Call iso_read from cb table */                                           \
        int __ret = ((int (*)(int, void *, unsigned int))0xA00008A8)(fd, buf, len); \
        /* Restore $gp (r28) */                                                     \
        __asm__ volatile("la   r28, _gp");                                          \
        /* Yield the return value */                                                \
        __ret;                                                                      \
    })

/* Call the ISO lseek routine at 0xA00008B4(int, long, int), save its int return,
   then restore $gp (r28) before yielding return. */
#define iso_lseek(fd, offset, whence)                                              \
    ({                                                                             \
       /* Call iso_lseek from cb table */                                          \
        int __ret = ((int (*)(int, long, int))0xA00008B4)(fd, offset, whence);     \
       /* Restore $gp (r28) */                                                     \
        __asm__ volatile("la   r28, _gp");                                         \
       /* Yield the return value */                                                \
        __ret;                                                                     \
    })

/* Call the ISO close routine at 0xA00008C0(int), save its int return,
   then restore $gp (r28) before yielding return. (return is -1 if error) */
#define iso_close(fd)                                         \
    ({                                                        \
        /* Call iso_close from the cb table */                \
        int __ret = ((int (*)(int))0xA00008C0)(fd);           \
        /* Restore $gp (r28) */                               \
        __asm__ volatile("la   r28, _gp");                    \
        /* Yield the return value */                          \
        __ret;                                                \
    })

/* Call the drvusbh_Init routine at 0xA000092C, save its int return,
   then restore $gp (r28) and yield return. */
#define drvusbh_init()                                        \
    ({                                                        \
        /* Call drvusbh_init from the cb table */             \
        int __ret = ((int (*)(void))0xA000092C)();            \
        /* Restore $gp (r28) */                               \
        __asm__ volatile("la   r28, _gp");                    \
        /* Yield the return value */                          \
        __ret;                                                \
    })

/* Call the drvusbh_luninit routine at 0xA0000938(int), save its int return,
   then restore $gp (r28) and yield return. */
#define drvusbh_luninit(LUN)                                  \
    ({                                                        \
        /* Call iso_close from the cb table */                \
        int __ret = ((int(*)(int))0xA0000938)(LUN);            \
        /* Restore $gp (r28) */                               \
        __asm__ volatile("la   r28, _gp");                    \
        /* Yield the return value */                          \
        __ret;                                                \
    })

/* Call the drvusbh_readsector routine at 0xA0000950(unsigned int, unsigned int, unsigned char *, int), save its int return,
   then restore $gp (r28) and yield return. */
#define drvusbh_readsector(block, blocknum, inaddr, lun)      \
    ({                                                        \
        /* Call iso_close from the cb table */                \
        int __ret = ((int (*) (unsigned int, unsigned int, unsigned char *, int))0xA0000950)(block, blocknum, inaddr, lun); \
        /* Restore $gp (r28) */                               \
        __asm__ volatile("la   r28, _gp");                    \
        /* Yield the return value */                          \
        __ret;                                                \
    })

/* Call the drvusbh_writesector routine at 0xA000095C(unsigned int, unsigned int, unsigned char *, int), save its int return,
   then restore $gp (r28) and yield return. */
#define drvusbh_writesector(block, blocknum, outaddr, lun)      \
    ({                                                        \
        /* Call iso_close from the cb table */                \
        int __ret = ((int (*) (unsigned int, unsigned int, unsigned char *, int))0xA000095C)(block, blocknum, outaddr, lun); \
        /* Restore $gp (r28) */                               \
        __asm__ volatile("la   r28, _gp");                    \
        /* Yield the return value */                          \
        __ret;                                                \
    })	   	

/* Call the RFID detect routine at 0xA0000830, save its int return,
   then restore $gp (r28) and yield return. */
#define rfid_det()                                                      \
    ({                                                                  \
        /* Call rfid_det from the cb table */                           \
        unsigned int __ret = ((unsigned int (*)(void))0xA0000830)();    \
        /* Restore $gp (r28) */                                         \
        __asm__ volatile("la   r28, _gp");                              \
        /* Yield the return value */                                    \
        __ret;                                                          \
    })

#ifdef __cplusplus
}
#endif

#endif /* __HYPERSCAN_H__ */
