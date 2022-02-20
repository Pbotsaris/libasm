#include "src/libasm.h"

void test_strlen(void);
void test_strchr(void);
void test_memset(void);
void test_memcpy(void);
void test_strcmp(void);
void test_memmove(void);
void test_strncmp(void);

int main(void)
{
  test_strlen();
  test_strchr();
  test_memset();
  test_memcpy();
  test_strcmp();
  test_memmove();
  test_strncmp();

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
