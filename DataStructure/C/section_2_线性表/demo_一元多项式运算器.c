/*
 * =====================================================================================
 *
 *       Filename:  demo_一元多项式运算器.c
 *
 *    Description:  一元多项式运算器
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 14时42分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial {
	float	coef;
	int		expn;
	struct Polynomial	*next;
}Polynomial, *Polyn;

Polyn createPoly() {		//建立多项式
	Polynomial	*head, *rear, *s;
	int		c, e;

	head = (Polynomial *)malloc(sizeof(Polynomial));	//建立多项式头结点
	rear = head;										//rear始终指向单链表的尾,便于尾插法建表
	scanf("%d,%d", &c, &e);								//键入多项式的系数和指数
	while( c != 0 ) {				//如果c=0,则代表多项式输入结束
		s = (Polynomial *)malloc(sizeof(Polynomial));		//申请新的结点
		s->coef = c;
		s->expn = e;
		rear->next = s;
		rear = s;
		scanf("%d,%d", &c, &e);
	}
	rear->next = NULL;		//将表中最后一个结点的next置为NULL,结束
	return head;
}

void printPolyn( Polyn P ) {	//输出多项式
	Polyn q = P->next;
	int flag = 1;

	if ( !q ) {
		putchar('0');
		printf("\n");
		return;
	}
	while(q) {
		if ( q->coef > 0 && flag != 1 ) {
			putchar('+');
		}
		if ( q->coef != 1 && q->coef != -1 ) {
			printf("%g", q->coef);
			if ( q->expn == 1 ) {
				putchar('X');
			}
			else if ( q->expn ) {
				printf("X^%d", q->expn);
			}
		}
		else {
			if ( q->coef == 1 ) {
				if ( !q->expn ) {
					putchar('1');
				}
				else if ( q->expn == 1 ) {
					putchar('X');
				}
				else {
					printf("X^%d", q->expn);
				}
			}
			if ( q->coef == -1 ) {
				if ( !q->expn) {
					printf("-1");
				}
				else if ( q->expn == 1 ) {
					printf("-X");
				}
				else {
					printf("-X^%d", q->expn);
				}
			}
		}
		q = q->next;
		flag ++;
	}
	printf("\n");
}

Polyn	addPolyn( Polyn pa, Polyn pb ) {	//两个多项式相加
	Polyn	qa = pa->next;
	Polyn	qb = pb->next;
	Polyn	headc, pc, qc;

	pc = (Polyn)malloc( sizeof(Polynomial) );	//单链表pc用来存放pa+pb的和
	pc->next = NULL;
	headc = pc;

	while( qa != NULL && qb != NULL ) {			//当两个多项式均未扫描结束时
		qc = (Polyn)malloc( sizeof(Polynomial) );
		if ( qa->expn < qb->expn ) {		//规则1
			qc->coef = qa->coef;
			qc->expn = qa->expn;
			qa = qa->next;
		}
		else if ( qa->expn == qb->expn ) {	//规则2
			qc->coef = qa->coef + qb->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			qb = qb->next;
		}
		else {								//规则3
			qc->coef = qb->coef;
			qc->expn = qb->expn;
			qb = qb->next;
		}

		if ( qc->coef != 0 ) {
			qc->next = pc->next;
			pc->next = qc;
			pc = qc;
		}
		else {
			free(qc);
		}
	}

	while( qa != NULL ) {		//pa中如果有剩余项,将剩余项插入到pc当中
		qc = (Polyn)malloc(sizeof(Polynomial));
		qc->coef = qa->coef;
		qc->expn = qa->expn;
		qa = qa->next;
		qc ->next = pc->next;
		pc->next = qc;
		pc = qc;
	}
	return headc;
}

Polyn subtractPolyn( Polyn pa, Polyn pb ) {
	Polyn	h = pb;
	Polyn	p = pb->next;
	Polyn	pd;

	while( p ) {
		p->coef *= -1;
		p = p->next;
	}
	pd = addPolyn(pa, h);
	for ( p = h->next; p; p = p->next ) {
		p->coef *= -1;
	}
	return pd;
}

int main(int argc, char *argv[])
{
	Polyn p1, p2, p3;
	
	printf("输入第一个多项式:\n");
	p1 = createPoly();
	printf("输入第二个多项式:\n");
	p2 = createPoly();

	printf("--------------亲爱的多项式们(1)----------------\n");
	printPolyn(p1);
	printf("--------------亲爱的多项式们(2)----------------\n");
	printPolyn(p2);

	p3 = addPolyn(p1, p2);
	printf("--------------亲爱的多项式们(3)----------------\n");
	printPolyn(p3);

	p3 = subtractPolyn(p2, p1);
	printf("--------------亲爱的多项式们(4)----------------\n");
	printPolyn(p3);

	
	return EXIT_SUCCESS;
}

