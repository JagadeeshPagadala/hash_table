
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jagadeesh Pagadala");

static int hash_init (void)
{
	return 0;
}

static void hash_clean(void)
{
	
}

module_init(hash_init);
module_exit(hash_clean);
