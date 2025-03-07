/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : FAT1.h
**     Project     : DataLogger
**     Processor   : MK64FN1M0VLL12
**     Component   : FAT_FileSystem
**     Version     : Component 01.203, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-11-14, 11:42, # CodeGen: 16
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         open             - FRESULT FAT1_open(FIL *fp, const XCHAR *path, BYTE mode);
**         close            - FRESULT FAT1_close(FIL *fp);
**         read             - FRESULT FAT1_read(FIL *fp, void *buff, UINT btr, UINT *br);
**         write            - FRESULT FAT1_write(FIL *fp, const *void buff, UINT btw, UINT *bw);
**         opendir          - FRESULT FAT1_opendir(DIR *dj, const XCHAR *path);
**         readdir          - FRESULT FAT1_readdir(DIR *dj, FILINFO *fno);
**         lseek            - FRESULT FAT1_lseek(FIL *fp, DWORD ofs);
**         unlink           - FRESULT FAT1_unlink(const XCHAR *path);
**         mount            - FRESULT FAT1_mount(FATFS *fs, const TCHAR* path, byte opt);
**         getfree          - FRESULT FAT1_getfree(const XCHAR *path, dword *nclst, FATFS **fatfs);
**         sync             - FRESULT FAT1_sync(FIL *fp);
**         rename           - FRESULT FAT1_rename(const XCHAR *path_old, const XCHAR *path_new);
**         isWriteProtected - bool FAT1_isWriteProtected(uint8_t *drvStr);
**         isDiskPresent    - bool FAT1_isDiskPresent(uint8_t *drvStr);
**         mkdir            - FRESULT FAT1_mkdir(const XCHAR *path);
**         chmod            - FRESULT FAT1_chmod(const TCHAR* FileName, uint8_t Attribute, uint8_t...
**         truncate         - FRESULT FAT1_truncate(FIL *FileObject);
**         stat             - FRESULT FAT1_stat(const TCHAR* FileName, FILINFO* FileInfo);
**         utime            - FRESULT FAT1_utime(const TCHAR* FileName, const FILINFO* TimeDate);
**         mkfs             - FRESULT FAT1_mkfs(byte drive, uint8_t PartitioningRule, UINT  AllocSize);
**         chdir            - FRESULT FAT1_chdir(const TCHAR* Path);
**         chdrive          - FRESULT FAT1_chdrive(uint8_t Drive);
**         getcwd           - FRESULT FAT1_getcwd(TCHAR* Buffer, UINT BufferLen);
**         errFResultMsg    - char* FAT1_errFResultMsg(int errNo);
**         errDResultMsg    - char* FAT1_errDResultMsg(int errNo);
**         f_gets           - FAT1_CHARP FAT1_f_gets(TCHAR* buff, int len, FIL *fil);
**         f_puts           - FAT1_INT FAT1_f_puts(const TCHAR* str, FIL *fil);
**         f_putc           - FAT1_INT FAT1_f_putc(TCHAR c, FIL *fil);
**         f_printf         - FAT1_INT FAT1_f_printf(FIL* fil, const TCHAR* str, ...);
**         f_eof            - byte FAT1_f_eof(FIL *fil);
**         f_error          - uint8_t FAT1_f_error(FIL *fil);
**         f_tell           - dword FAT1_f_tell(FIL *fil);
**         f_size           - dword FAT1_f_size(FIL *fil);
**         f_getlabel       - FRESULT FAT1_f_getlabel(const TCHAR* path, TCHAR* label, DWORD* vsn);
**         f_setlabel       - FRESULT FAT1_f_setlabel(const TCHAR* label);
**         f_expand         - FRESULT FAT1_f_expand(FIL* fp, FSIZE_t fsz, BYTE opt);
**         f_findfirst      - FRESULT FAT1_f_findfirst(DIR* dp, FILINFO* fno, const TCHAR* path, const...
**         f_findnext       - FRESULT FAT1_f_findnext(DIR* dp, FILINFO* fno);
**         f_opendir        - FRESULT FAT1_f_opendir(DIR* dp, const TCHAR* path);
**         f_readdir        - FRESULT FAT1_f_readdir(DIR *dj, FILINFO *fno);
**         f_closedir       - FRESULT FAT1_f_closedir(DIR* dp);
**         get_fattime      - uint32_t FAT1_get_fattime(void);
**         Deinit           - uint8_t FAT1_Deinit(void);
**         Init             - uint8_t FAT1_Init(void);
**
**Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**All Rights Reserved.
**
**Redistribution and use in source and binary forms, with or without modification,
**are permitted provided that the following conditions are met:
**
**o Redistributions of source code must retain the above copyright notice, this list
**  of conditions and the following disclaimer.
**
**o Redistributions in binary form must reproduce the above copyright notice, this
**  list of conditions and the following disclaimer in the documentation and/or
**  other materials provided with the distribution.
**
**o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**  contributors may be used to endorse or promote products derived from this
**  software without specific prior written permission.
**
**THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**http: www.freescale.com
**mail: support@freescale.com
** ###################################################################*/
/*!
** @file FAT1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup FAT1_module FAT1 module documentation
**  @{
*/         

#ifndef __FAT1_H
#define __FAT1_H

/* MODULE FAT1. */
/* Wrappers to FatFS types and constants */
#define FAT1_FATFS            FATFS
#define FAT1_DIR              DIR
#define FAT1_FIL              FIL
#define FAT1_FILINFO          FILINFO
#define FAT1_FS_READONLY      _FS_READONLY
#define FAT1_USE_LFN          _USE_LFN
#define FAT1_MAX_LFN          _MAX_LFN
#define FAT1_FS_REENTRANT     _FS_REENTRANT
#define FAT1_MAX_SS           _MAX_SS
#define FAT1_FS_RPATH         _FS_RPATH
#define FAT1_FRESULT          FRESULT
#define FAT1_DRESULT          DRESULT

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "SD1.h"
#include "TmDt1.h"
#include "UTIL1.h"
#include "ff.h"
#include "diskio.h"

#include "Cpu.h"


#ifndef __BWUserType_FAT1_CHARP
#define __BWUserType_FAT1_CHARP
  typedef char * FAT1_CHARP;           /* alias to a char pointer */
#endif
#ifndef __BWUserType_FAT1_INT
#define __BWUserType_FAT1_INT
  typedef int FAT1_INT;                /* alias to int type. */
#endif

#define FAT1_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */

#define FAT1_USE_RTOS_DYNAMIC_MEMORY  (0 && configSUPPORT_DYNAMIC_ALLOCATION)  /* 1: use RTOS dynamic memory allocation, 0: use static memory */



#define FAT1_open(fp, path, mode) \
  f_open(fp, path, mode)
/*
** ===================================================================
**     Method      :  FAT1_open (component FAT_FileSystem)
**     Description :
**         Open/Create a file
**     Parameters  :
**         NAME            - DESCRIPTION
**         fp              - Pointer to the blank file object structure
**         path            - Pointer to a null-terminated string that
**                           specifies the file name to create or open.
**         mode            - Specifies the type of access and open
**                           method for the file. It is specified by a
**                           combination of following flags.
**                           FA_READ: Specifies read access to the
**                           object. Data can be read from the file.
**                           Combine with FA_WRITE for read-write access.
**                           FA_WRITE: Specifies write access to the
**                           object. Data can be written to the file.
**                           Combine with FA_READ for read-write access.
**                           FA_OPEN_EXISTING: Opens the file. The
**                           function fails if the file is not existing.
**                           (Default)
**                           FA_OPEN_ALWAYS: Opens the file if it is
**                           existing. If not, a new file is created. To
**                           append data to the file, use f_lseek
**                           function after file open in this method.
**                           FA_CREATE_NEW: Creates a new file. The
**                           function fails if the file is already
**                           existing.
**                           FA_CREATE_ALWAYS: Creates a new file. If
**                           the file is existing, it is truncated and
**                           overwritten.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_close(fp) \
  f_close(fp)

/*
** ===================================================================
**     Method      :  FAT1_close (component FAT_FileSystem)
**     Description :
**         Close a file
**     Parameters  :
**         NAME            - DESCRIPTION
**         fp              - Pointer to the open file object structure to
**                           be closed.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_read(fp, buff, btr, br) \
  f_read(fp, buff, btr, br)

/*
** ===================================================================
**     Method      :  FAT1_read (component FAT_FileSystem)
**     Description :
**         Read file
**     Parameters  :
**         NAME            - DESCRIPTION
**         fp              - Pointer to the file object
**         buff            - Pointer to the data buffer
**         btr             - Number of bytes to read
**         br              - Pointer to the number of bytes read
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_write(fp, buff, btw, bw) \
  f_write(fp, buff, btw, bw)

/*
** ===================================================================
**     Method      :  FAT1_write (component FAT_FileSystem)
**     Description :
**         Write to a file
**     Parameters  :
**         NAME            - DESCRIPTION
**         fp              - Pointer to the file object structure 
**         buff            - Pointer to the data to be written
**         btw             - Number of bytes to write
**         bw              - Pointer to the variable to return number of
**                           bytes written
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_opendir(dj, path) \
  f_opendir(dj, path)

/*
** ===================================================================
**     Method      :  FAT1_opendir (component FAT_FileSystem)
**     Description :
**         Open a directory
**     Parameters  :
**         NAME            - DESCRIPTION
**         dj              - Pointer to the blank directory object to be
**                           created.
**         path            - Pointer to the null-terminated string
**                           that specifies the directory name to be
**                           opened.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_readdir(dj, fno) \
  f_readdir(dj, fno)

/*
** ===================================================================
**     Method      :  FAT1_readdir (component FAT_FileSystem)
**     Description :
**         Read a directory item
**     Parameters  :
**         NAME            - DESCRIPTION
**         dir             - Pointer to the open directory object
**         fno             - Pointer to the file information structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_lseek(fp, ofs) \
  f_lseek(fp, ofs)

/*
** ===================================================================
**     Method      :  FAT1_lseek (component FAT_FileSystem)
**     Description :
**         The f_lseek function moves the file read/write pointer of an
**         open file object. It can also be used to increase the file
**         size (cluster pre-allocation).
**     Parameters  :
**         NAME            - DESCRIPTION
**         fp              - Pointer to the file object
**         ofs             - File pointer from top of file
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_unlink(path) \
  f_unlink(path)

/*
** ===================================================================
**     Method      :  FAT1_unlink (component FAT_FileSystem)
**     Description :
**         Remove a file or directory
**     Parameters  :
**         NAME            - DESCRIPTION
**         path            - Pointer to the object name
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_mount(fs, path, opt) \
  f_mount(fs, path, opt)

/*
** ===================================================================
**     Method      :  FAT1_mount (component FAT_FileSystem)
**     Description :
**         Mount/unmount a logical drive
**     Parameters  :
**         NAME            - DESCRIPTION
**         fs              - pointer to the new file system object (NULL
**                           for unmount)
**       * path            - Logical drive number to be
**                           mounted/unmounted
**         opt             - options: 0:Do not mount (delayed mount), 1:
**                           Mount immediately
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_getfree(path, nclst, fs) f_getfree(path, nclst, fs)
/*
** ===================================================================
**     Method      :  FAT1_getfree (component FAT_FileSystem)
**     Description :
**         Get Number of Free Clusters
**     Parameters  :
**         NAME            - DESCRIPTION
**         path            - Pointer to the logical drive number
**                           (root dir)
**       * nclst           - Pointer to the variable to return
**                           number of free clusters
**         fatfs           - Pointer to pointer to file system
**                           object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_sync(fp) \
  f_sync(fp)

/*
** ===================================================================
**     Method      :  FAT1_sync (component FAT_FileSystem)
**     Description :
**         Flush cached data of a writing file
**     Parameters  :
**         NAME            - DESCRIPTION
**         fp              - Pointer to the file object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_rename(path_old, path_new) \
  f_rename(path_old, path_new)
/*
** ===================================================================
**     Method      :  FAT1_rename (component FAT_FileSystem)
**     Description :
**         Delete a file or directory
**     Parameters  :
**         NAME            - DESCRIPTION
**         path_old        - Pointer to old object name
**         path_new        - Pointer to new object name
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

bool FAT1_isWriteProtected(uint8_t *drvStr);

/*
** ===================================================================
**     Method      :  FAT1_isWriteProtected (component FAT_FileSystem)
**     Description :
**         Determines if the file system is write protected.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * drvStr          - Pointer to drive string, e.g. "" or
**                           "0"
**     Returns     :
**         ---             - TRUE if file system is write protected
** ===================================================================
*/

#define FAT1_mkdir(path) \
  f_mkdir(path)
/*
** ===================================================================
**     Method      :  FAT1_mkdir (component FAT_FileSystem)
**     Description :
**         Creates a directory
**     Parameters  :
**         NAME            - DESCRIPTION
**         path            - Name of directory to be created
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_chmod(FileName, Attribute, AttributeMask) \
  f_chmod(FileName, Attribute, AttributeMask)

/*
** ===================================================================
**     Method      :  FAT1_chmod (component FAT_FileSystem)
**     Description :
**         Changes the attribute of a file or directory
**         Following attribute flags to be set in one or more
**         combination of the following flags. The specified flags are
**         set and others are cleared.
**         AM_RDO	Read only
**         AM_ARC	Archive
**         AM_SYS	System
**         AM_HID	Hidden
**     Parameters  :
**         NAME            - DESCRIPTION
**         FileName        - Pointer to the file or directory
**         Attribute       - Attribute flags. Attribute
**                           flags to be set in one or more combination
**                           of the following flags. The specified flags
**                           are set and others are cleard.
**         AttributeMask   - Attribute mask.
**                           Attribute mask that specifies which
**                           attribute is changed. The specified
**                           aattributes are set or cleard.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_truncate(FILP) \
  f_truncate(FILP)

/*
** ===================================================================
**     Method      :  FAT1_truncate (component FAT_FileSystem)
**     Description :
**         Truncates the file size.
**         The truncate() function truncates the file size to the
**         current file read/write point. This function has no effect
**         if the file read/write pointer is already pointing end of
**         the file.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * FileObject      - Pointer to the file object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_stat(FileName, FileInfo) \
  f_stat(FileName, FileInfo)

/*
** ===================================================================
**     Method      :  FAT1_stat (component FAT_FileSystem)
**     Description :
**         The f_stat gets the information of a file or directory. For
**         details of the infomation, refer to the FILINFO structure
**         and f_readdir function. This function is not supported in
**         minimization level of >= 1.
**     Parameters  :
**         NAME            - DESCRIPTION
**         FileName        - Pointer to the file or directory
**                           path
**       * FileInfo        - Pointer to the FILINFO structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_utime(FileName, TimeDate) \
  f_utime(FileName, TimeDate)

/*
** ===================================================================
**     Method      :  FAT1_utime (component FAT_FileSystem)
**     Description :
**         The f_utime function changes the timestamp of a file or
**         directory
**     Parameters  :
**         NAME            - DESCRIPTION
**       * FileName        - Pointer to the file or directory
**                           path
**       * TimeDate        - Pointer to time and data to be
**                           set
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_mkfs(drive, PartitioningRule, AllocSize) \
  f_mkfs(drive, PartitioningRule, AllocSize)

/*
** ===================================================================
**     Method      :  FAT1_mkfs (component FAT_FileSystem)
**     Description :
**         The f_mkfs fucntion creates a file system on the drive.
**     Parameters  :
**         NAME            - DESCRIPTION
**         drive           - Logical drive number
**         PartitioningRule - When 0 is given,
**                           a partition table is created into the
**                           master boot record and a primary DOS
**                           partition is created and then an FAT volume
**                           is created on the partition. This is called
**                           FDISK format and used for harddisk and
**                           memory cards. When 1 is given, the FAT
**                           volume starts from the first sector on the
**                           drive without partition table. This is
**                           called SFD format and used for floppy disk
**                           and most optical disk
**         AllocSize       - Size of the allocation unit.
**                           Force the allocation unit (cluster) size in
**                           unit of byte. The value must be power of 2
**                           and between the sector size and 128 times
**                           sector size. When invalid value is
**                           specified, the cluster size is determined
**                           depends on the volume size.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_chdir(Path) \
  f_chdir(Path)

/*
** ===================================================================
**     Method      :  FAT1_chdir (component FAT_FileSystem)
**     Description :
**         The f_chdir function changes the current directory of the
**         logical drive. The current directory of a drive is
**         initialized to the root directory when the drive is
**         auto-mounted. Note that the current directory is retained in
**         the each file system object so that it also affects other
**         tasks that using the drive.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Path            - Pointer to the path name
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_chdrive(Drive) \
  f_chdrive(Drive)

/*
** ===================================================================
**     Method      :  FAT1_chdrive (component FAT_FileSystem)
**     Description :
**         The f_chdrive function changes the current drive. The
**         initial value of the current drive number is 0. Note that
**         the current drive is retained in a static variable so that
**         it also affects other tasks that using the file functions.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Drive           - Logical drive number
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_getcwd(Buffer, BufferLen) \
  f_getcwd(Buffer, BufferLen)

/*
** ===================================================================
**     Method      :  FAT1_getcwd (component FAT_FileSystem)
**     Description :
**         The f_getcwd function retrieves the current directory of the
**         current drive in full path string including drive number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Buffer          - Pointer to the buffer to receive the
**                           current directory string.
**         BufferLen       - Size of the buffer in unit of
**                           TCHAR.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

char* FAT1_errFResultMsg(int errNo);
/*
** ===================================================================
**     Method      :  FAT1_errFResultMsg (component FAT_FileSystem)
**     Description :
**         Returns for a given FatFs FRESULT error code a string
**     Parameters  :
**         NAME            - DESCRIPTION
**         errNo           - FatFs error code
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

char* FAT1_errDResultMsg(int errNo);
/*
** ===================================================================
**     Method      :  FAT1_errDResultMsg (component FAT_FileSystem)
**     Description :
**         Returns for a given FatFs DRESULT error code a string
**     Parameters  :
**         NAME            - DESCRIPTION
**         errNo           - FatFs error code
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

bool FAT1_isDiskPresent(uint8_t *drvStr);

/*
** ===================================================================
**     Method      :  FAT1_isDiskPresent (component FAT_FileSystem)
**     Description :
**         Determines if the disk is present or not (e.g. disk inserted).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * drvStr          - drive string, "" or "0" or "1"
**     Returns     :
**         ---             - TRUE if file system is write protected
** ===================================================================
*/

#define FAT1_f_gets(buff, len, fil) \
  f_gets(buff,len,fil)

/*
** ===================================================================
**     Method      :  FAT1_f_gets (component FAT_FileSystem)
**     Description :
**         Get a string from the file
**     Parameters  :
**         NAME            - DESCRIPTION
**       * buff            - Pointer to the string buffer to read 
**         len             - Size of string buffer (characters)
**         fil             - Pointer to the file object
**     Returns     :
**         ---             - zero (NULL) if failed, otherwise a string
**                           to the buffer is returned.
** ===================================================================
*/

#define FAT1_f_puts(str, fil) \
  f_puts(str, fil)

/*
** ===================================================================
**     Method      :  FAT1_f_puts (component FAT_FileSystem)
**     Description :
**         Put a string to the file
**     Parameters  :
**         NAME            - DESCRIPTION
**       * buff            - A character to be output
**         fil             - Pointer to the file object
**     Returns     :
**         ---             - number of characters written.
** ===================================================================
*/

#define FAT1_f_putc(c, fil) \
  f_putc(c, fil)

/*
** ===================================================================
**     Method      :  FAT1_f_putc (component FAT_FileSystem)
**     Description :
**         Put a character to the file
**     Parameters  :
**         NAME            - DESCRIPTION
**       * buff            - A character to be output
**         fil             - Pointer to the file object
**     Returns     :
**         ---             - 1 if ok, EOF otherwise
** ===================================================================
*/

#define FAT1_f_printf \
  f_printf

/*
** ===================================================================
**     Method      :  FAT1_f_printf (component FAT_FileSystem)
**     Description :
**         Put a formatted string to the file
**     Parameters  :
**         NAME            - DESCRIPTION
**         Variable_1      - Pointer to the file object
**         str             - Pointer to the format string
**         Variable_2      - Optional arguments...
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_eof(fp) \
  f_eof(fp)

/*
** ===================================================================
**     Method      :  FAT1_f_eof (component FAT_FileSystem)
**     Description :
**         Wrapper to to the f_eof() macro. Returns 1 if at the end of
**         the file, 0 otherwise.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * fp              - Pointer to file object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_error(fp) \
  f_error(fp)

/*
** ===================================================================
**     Method      :  FAT1_f_error (component FAT_FileSystem)
**     Description :
**         Wrapper to to the f_eof() macro. Returns 1 if at the end of
**         the file, 0 otherwise.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * fp              - Pointer to file object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_tell(fp) \
  f_tell(fp)

/*
** ===================================================================
**     Method      :  FAT1_f_tell (component FAT_FileSystem)
**     Description :
**         Wrapper to to the f_tell() macro. Returns the file
**         read/write pointer (0 on file open).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * fp              - Pointer to file object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_size(fp) \
  f_size(fp)

/*
** ===================================================================
**     Method      :  FAT1_f_size (component FAT_FileSystem)
**     Description :
**         Wrapper to to the f_size() macro. Returns the file size.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * fp              - Pointer to file object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FAT1_Init(void);
/*
** ===================================================================
**     Method      :  FAT1_Init (component FAT_FileSystem)
**     Description :
**         Initializes the device driver.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t FAT1_Deinit(void);
/*
** ===================================================================
**     Method      :  FAT1_Deinit (component FAT_FileSystem)
**     Description :
**         Deinitializes the driver.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint32_t FAT1_get_fattime(void);
/*
** ===================================================================
**     Method      :  FAT1_get_fattime (component FAT_FileSystem)
**     Description :
**         Returns the current time
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_getlabel(path, label, vsn) \
  f_getlabel(path, label, vsn)
/*
** ===================================================================
**     Method      :  FAT1_f_getlabel (component FAT_FileSystem)
**     Description :
**         Get volume label
**     Parameters  :
**         NAME            - DESCRIPTION
**       * path            - Pointer to path name of the logical
**                           drive number
**       * label           - Pointer to a buffer to return the
**                           volume label
**         vsn             - 
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_setlabel(label) \
  f_setlabel(label);
/*
** ===================================================================
**     Method      :  FAT1_f_setlabel (component FAT_FileSystem)
**     Description :
**         Set Volume Label 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * label           - Pointer to the volume label to set
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_expand(fp, fsz, opt) \
  f_expand(fp, fsz, opt);
/*
** ===================================================================
**     Method      :  FAT1_f_expand (component FAT_FileSystem)
**     Description :
**         Allocate a Contiguous Blocks to the File
**     Parameters  :
**         NAME            - DESCRIPTION
**       * fp              - Pointer to the file object
**         fsz             - File size to be expanded to
**         opt             - Operation mode 0:Find and prepare or 1:
**                           Find and allocate
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_findfirst(dp, fno, path, pattern) \
  f_findfirst(dp, fno, path, pattern)
/*
** ===================================================================
**     Method      :  FAT1_f_findfirst (component FAT_FileSystem)
**     Description :
**         Find FirstFile
**     Parameters  :
**         NAME            - DESCRIPTION
**         dp              - Pointer to the open directory object
**         fno             - Pointer to the file information structure
**         path            - Pointer to the directory to open
**         pattern         - Pointer to the matching pattern
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_findnext(dp, fno) \
  f_findnext(dp, fno)
/*
** ===================================================================
**     Method      :  FAT1_f_findnext (component FAT_FileSystem)
**     Description :
**         Find Next File
**     Parameters  :
**         NAME            - DESCRIPTION
**         dp              - Pointer to the open directory object
**         fno             - Pointer to the file information structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_opendir(dp, path) \
  f_opendir(dp, path)
/*
** ===================================================================
**     Method      :  FAT1_f_opendir (component FAT_FileSystem)
**     Description :
**         Open a directory
**     Parameters  :
**         NAME            - DESCRIPTION
**         dp              - Pointer to the open directory object
**         path            - path of directory
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_closedir(dp) \
  f_closedir(dp)
/*
** ===================================================================
**     Method      :  FAT1_f_closedir (component FAT_FileSystem)
**     Description :
**         Close a directory
**     Parameters  :
**         NAME            - DESCRIPTION
**         dp              - Pointer to the open directory object
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define FAT1_f_readdir(dj, fno) \
  f_readdir(dj, fno)
/*
** ===================================================================
**     Method      :  FAT1_f_readdir (component FAT_FileSystem)
**     Description :
**         Read a directory item
**     Parameters  :
**         NAME            - DESCRIPTION
**         dir             - Pointer to the open directory object
**         fno             - Pointer to the file information structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END FAT1. */

#endif
/* ifndef __FAT1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
