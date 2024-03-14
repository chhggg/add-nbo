#include "nbo.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("usage : ./add-nbo <file1> <file2>\n");
        return (1);
    }

    FILE *fp1, *fp2;
    uint32_t a, b, s, ret1, ret2;

    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    if (!fp1 || !fp2){
        printf("fopen error : %s\n", strerror(errno));
        file_close(fp1, fp2);
        return (1);
    }

    ret1 = fread(&a, sizeof(uint32_t), 1, fp1);
	ret2 = fread(&b, sizeof(uint32_t), 1, fp2);

    if (ret1 != 1 || ret2 != 1 ){
        printf("fread error\n");
        file_close(fp1, fp2);
        return (1);
    }

    a = ntohl(a);
    b = ntohl(b);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);

    file_close(fp1, fp2);
    return (0);
}