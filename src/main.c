#include "src/libasm.h"

void test_strlen(void);
void test_strchr(void);
void test_memset(void);
void test_memcpy(void);
void test_strcmp(void);
void test_memmove(void);
void test_strncmp(void);
void test_strcasecmp(void);
void test_index(void);
void test_read(void);
void test_write(void);

int main(void)
{
  // you can comment tests at anytime if you want to test something in particular.
  test_strlen();
  test_strchr();
  test_memset();
  test_memcpy();
  test_strcmp();
  test_memmove();
  test_strncmp();
  test_strcasecmp();
  test_index();
  test_read();
  test_write();

  return 0;
}

void test_memmove(void)
{
  // let's copy some overlapping data
  char str[] = "pedro jose\n";
  char strb[] = "pedro jose\n";

  my_memcpy(str + 1, str + 3, 2 * sizeof(char));
  memcpy(strb + 1, strb + 3, 2 * sizeof(char));

  if((strcmp(str, strb)) != 0)
    printf("memmove failed. Was %s and should be %s\n", str, strb);
  else
    printf("memmove passed!\n");

}

void test_strlen(void)
{
  char *test_str = "hello";

 size_t len = my_strlen(test_str);
 size_t lenb = strlen(test_str);

  if(len != lenb)
      printf("strlen failed: was: %ld should be %ld\n", len, lenb);
  else
     printf("strlen passed!\n");
}

void test_strchr(void)
{
 char *str =  my_strchr("hello,world", ',');
 char *strb = strchr("hello,world", ',');

  if(str)
  {
    if((strcmp(str, strb)) != 0)
       printf("strchr failed. Was %s and should be %s\n", str, strb);
    else
      printf("strchr passed!\n");
  }
  else
    printf("failed: NULL was returned\n");
}

void test_memset(void)
{
  int len = 10, valid = 1;
  char buff[len], buffb[len];
  char *ret, *retb;

 ret = my_memset(buff, 'w', len);
 retb = memset(buffb, 'w', len);

 for(int i = 0; i < len; i++)
      if(ret[i] != retb[i] || buff[i] != buffb[i])
          valid = 0;

  buff[len - 1]  = '\0';
  buffb[len - 1]  = '\0';

  if(!valid)
       printf("memset failed. Was %s and should be %s\n", buff, buffb);
  else
      printf("memset passed!\n");
}

void test_memcpy(void)
{
  char src[] = "copying memory!\n";
  size_t len = strlen(src);
  char dest[len + 1];
  char destb[len + 1];

  my_memcpy(dest, src, len + 1);
  memcpy(destb, src, len + 1);

  if((strcmp(dest, destb)) != 0)
     printf("memcpy failed. Was: %s sould be: %s\n", dest, destb);
  else
     printf("memcpy passed!\n");
}

void test_strcmp(void)
{
  char stra[] = "hello";
  char strb[] = "helloo";
  char strc[] = "Hallo";
  char strd[] = "hell";
  char stre[] = "hello";

  int resa  = my_strcmp(stra, strb);
  int resb = strcmp(stra, strb);
  int resc = my_strcmp(stra, strc);
  int resd = strcmp(stra, strc);
  int rese = my_strcmp(stra, strd);
  int resf = strcmp(stra, strd);
  int resg = my_strcmp(stra, stre);
  int resh = strcmp(stra, stre);

  if(resa != resb)
    printf("strcmp failed. Was: %d, should be: %d \n", resa, resb);
  else if(resc != resd)
    printf("strcmp failed. Was: %d, should be: %d \n", resc, resd);
  else if(rese != resf)
    printf("strcmp failed. Was: %d, should be: %d \n", rese, resf);
  else if(resg != resh)
    printf("strcmp failed. Was: %d, should be: %d \n", resg, resh);
  else
   printf("strcmp passed!\n");
}

void test_strncmp(void)
{
  char stra[] = "hello";
  char strb[] = "hdllo";
  char strc[] = "Hallo";
  char strd[] = "hell0";
  char stre[] = "hello";
  size_t len = strlen(stra);

  int resa  = my_strncmp(stra, strb, len);
  int resb = strncmp(stra, strb, len);
  int resc = my_strncmp(stra, strc, len);
  int resd = strncmp(stra, strc, len);
  int rese = my_strncmp(stra, strd, len);
  int resf = strncmp(stra, strd, len);
  int resg = my_strncmp(stra, stre, len);
  int resh = strncmp(stra, stre, len);

  if(resa != resb)
    printf("strncmp failed. Was: %d, should be: %d \n", resa, resb);
  else if(resc != resd)
    printf("strncmp failed. Was: %d, should be: %d \n", resc, resd);
  else if(rese != resf)
    printf("strncmp failed. Was: %d, should be: %d \n", rese, resf);
  else if(resg != resh)
    printf("strncmp failed. Was: %d, should be: %d \n", resg, resh);
  else
   printf("strncmp passed!\n");
}


void test_strcasecmp(void)
{
  int res =  my_strcasecmp("pEdRo", "peDro");

  if(res != 0)
    printf("strcasecmp failed. Should return 0 but returned %d\n", res);
  else
    printf("strcasecmp passed!\n");

}


void test_index(void)
{

 // index finds the null char where strchr doesn't.
  char *res = my_index("testing", '\0');
  char *resb = my_index("testing", 't');
  char *resc = my_index("testing", 'z');

  if(res && resb[0] == 't' && !resc)
    printf("index passed!\n");
  else
    printf("index failed. Was %p, %c and %p and should be <a pointer address>, t and null\n", res, resb[0], resc);
}



void test_read(void)
{
  char buffer[30];  
  char bufferb[30];

  int fd = open("test_files/test_read.txt", O_RDONLY);// IMPORTANT: Make sure this file exists
  int res = my_read(fd, buffer, 21);
  close(fd);

  fd = open("test_files/test_read.txt", O_RDONLY);// IMPORTANT: Make sure this file exists
  int resb = read(fd, bufferb, 21);
  close(fd);
 
  if(((strcmp(buffer, bufferb)) != 0) || res != resb)
    printf("read failed. \n Was %s || size %d. \n should be %s || size %d \n", buffer, res, bufferb, resb);
  else
    printf("read passed!\n");

}

void test_write(void)
{
  int fd = open("test_files/test_write.txt", O_CREAT | O_WRONLY, S_IRWXU);
  int fdb = open("test_files/test_writeb.txt", O_CREAT | O_WRONLY, S_IRWXU);
 
  my_write(fd, "hello, world!", 13);
  write(fdb, "hello, world!", 13);

  close(fd);
  close(fdb);

  fd = open("test_files/test_write.txt", O_RDONLY);
  fdb = open("test_files/test_writeb.txt", O_RDONLY);

  char buffer[13];
  char bufferb[13];

  read(fd, buffer ,12);
  read(fdb, bufferb ,12);

  buffer[12] = '\0';
  buffer[12] = '\0';

  close(fd);
  close(fdb);

  if((strcmp(buffer, bufferb)) != 0)
      printf("write failed. Was : %s || should be: %s\n", buffer, bufferb);
  else
     printf("write passed!\n");
    
   remove("test_files/test_write.txt"); // IMPORTANT: This will remove the file after test. youn won't find this file in the test folder
   remove("test_files/test_writeb.txt"); // IMPORTANT: This will remove the file after test. youn won't find this file in the test folder
}
