#include "md5.h"
#include "platform.h"

int test_md5() {
    unsigned char buf[4096];
    unsigned char out[MD5_DIGEST_LENGTH];
    unsigned int n;
    md5Context ctx;

    md5_init(&ctx);

    n = posix_read(0, buf, sizeof(buf));
    md5_update(&ctx, buf, n);
    md5_final(out, &ctx);

    posix_write(1, out, sizeof(out));

    return 0;
}
