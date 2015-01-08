#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hashtable.h>
#include <linux/slab.h>

#define BITS 3

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jagadeesh Pagadala");

struct hashtable {
	char name[10];
	int age; 
	struct hlist_node my_hash_list;
};

/* Following statement will create hash table(array) named hash[1<<BITS]*/
DEFINE_HASHTABLE(my_hash, BITS);
/* Initialize the hash table*/
//hash_init(my_hash);

static int hash_table_init (void)
{
	struct hashtable *h1, *h2, *h3; 
	struct hashtable *tmp; 
	int i = 0, j = 0;

	h1 = kmalloc(sizeof *h1, GFP_KERNEL);
	if (!h1) {
		printk("cant allocate memory");
		return -ENOMEM;
	}

	h2 = kmalloc(sizeof *h2, GFP_KERNEL);
	if (!h2) {
		printk("cant allocate memory");
		return -ENOMEM;
	}

	h3 = kmalloc(sizeof *h3, GFP_KERNEL);
	if (!h3) {
		printk("cant allocate memory");
		return -ENOMEM;
	}

	memcpy(h1->name,"ab",2);
	h1->age = 2; 

	memcpy(h2->name,"abc",3);
	h2->age = 3; 

	memcpy(h3->name,"abcd",4);
	h3->age = 4; 

	hash_add(my_hash, &h1->my_hash_list, h1->age);
	hash_add(my_hash, &h2->my_hash_list, h2->age);
	hash_add(my_hash, &h3->my_hash_list, h3->age);

	hash_for_each(my_hash, i, tmp, my_hash_list) {
		printk("Entry[%d]: %s %d\n", i, tmp->name, tmp->age);
	}
	return 0;
}

static void hash_table_clean(void)
{
	
}

module_init(hash_table_init);
module_exit(hash_table_clean);
