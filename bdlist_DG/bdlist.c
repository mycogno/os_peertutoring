#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/slab.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

static LIST_HEAD(birthday_list);

struct birthday *createBirthday(int day, int month, int year) {

  /* TODO: 생일을 위한 메모리를 할당하고, 인자들을 채워 생일을 완성하세요. */
	struct birthday *newBirth;
	newBirth = kmalloc(sizeof(struct birthday), GFP_KERNEL);
	newBirth->day = day;
	newBirth->month = month;
	newBirth->year = year;
	return newBirth;
}

int simple_init(void) {
  printk("INSTALL MODULE: bdlist\n");

  /* TODO: 생일 목록을 하나씩 생성하는대로 연결리스트에 연결시키세요(노드 삽입)*/ 
  struct birthday* f1 = createBirthday(3,3,1999);
  struct birthday* f2 = createBirthday(22,1,2001);
  struct birthday* f3 = createBirthday(20,2,1974);
  struct birthday* f4 = createBirthday(7,11,1969);
  list_add(&f1->list, &birthday_list);
  list_add(&f2->list, &birthday_list);
  list_add(&f3->list, &birthday_list);
  list_add(&f4->list, &birthday_list);


  /* TODO: 완성된 연결리스트를 탐색하는 커널 함수를 사용하여 출력하세요. */
  struct birthday *cursor;
  list_for_each_entry(cursor, &birthday_list, list){
	  printk("Day %d.%d.%d\n", cursor->day, cursor->month, cursor->year);
	}
  printk("INSTALL COMPLETE\n");
  return 0;
}

void simple_exit(void) {
  /* 모듈을 제거할 때는 생성한 연결 리스트도 하나씩 제거하며 끝내도록 하세요. */
  /* 제거를 하기 전에 리스트가 "비어있을 경우""에 대한 예외처리를 하는게 좋겠죠? */
  printk("REMOVE MODULE: bdlist\n"); 
  struct birthday *cursor;
  struct list_head *ptr, *ptrn;  
  if(list_empty(&birthday_list)) {
    printk("List is Empty\n");
    return;
  }
  else{
    list_for_each_safe(ptr, ptrn, &birthday_list){
    cursor = list_entry(ptr, struct birthday, list);  
    printk("Removing %d.%d.%d\n", cursor->day, cursor->month, cursor->year);
    list_del(&cursor->list);
    }
    printk("REMOVE COMPLETE\n");
    return;
  }

  /* TODO: 이제 본격적으로 연결리스트를 탐색하면서 하나씩 제거하도록 하시면 됩니다. */
  
  /* 다만, 제거를 하면서 연결리스트를 탐색하면 문제가 생길 것 같은데 어떤 방법으로 해결 가능한지 생각해보세요. */

}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("make a list of birthdays and print");
MODULE_AUTHOR("2018045023");
