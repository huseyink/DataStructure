/*
 * stack.h
 *
 *  Created on: 22 Kas 2020
 *      Author: Huseyink
 */

#ifndef STACK_H_
#define STACK_H_


struct Stack {

	int count;
	unsigned int capacity;
	int* array;
};

/**
  * @brief  Stack yapisini belirlenen kapasite degerinde olusturur.
  * @param  Kapasite degeri
  * @retval Stack icin olusturulmus struct yapisi.
  */
struct Stack* stackInit(unsigned int capacity);

/**
  * @brief  Stack'e eleman ekler.
  * @param  Stack icin olusturulmus struct yapisi.
  * @param  Eklenecek veri
  * @retval EXIT TYPE
  */
int stackPush(struct Stack* stack, const int data);

/**
  * @brief  Stack'den eleman cikarir.
  * @param  Stack icin olusturulmus struct yapisi.
  * @param  Stack'den cikarilan eleman
  * @retval EXIT TYPE
  */
int stackPop(struct Stack* stack, int* data);

/**
  * @brief  Stack'in en basindaki elemani okur.
  * @param  Stack icin olusturulmus struct yapisi.
  * @param  Stack'den okunan eleman
  * @retval EXIT TYPE
  */
int stackPeek(struct Stack* stack, int* data);

/**
  * @brief  Stack'in bos mu sorgusunu yapar.
  * @param  Stack icin olusturulmus struct yapisi.
  * @retval int( 0: false, 1: true )
  */
int stackIsEmpty (const struct Stack* stack);

/**
  * @brief  Stack'in dolu mu sorgusunu yapar.
  * @param  Stack icin olusturulmus struct yapisi.
  * @retval int( 0: false, 1: true )
  */
int stackIsFull(const struct Stack* stack);

/**
  * @brief  Stack eleman sayisini dondurur.
  * @param  Stack icin olusturulmus struct yapisi.
  * @retval void
  */
int stackGetCount(const struct Stack* stack);

/**
  * @brief  Stack kapasite degerini dondurur.
  * @param  Stack icin olusturulmus struct yapisi.
  * @retval void
  */
int stackGetCapacity(const struct Stack* stack);

/**
  * @brief  Stack'i siler.
  * @param  Stack icin olusturulmus struct yapisinin adresi.
  * @retval void
  */
void stackClear(struct Stack** stack);

/**
  * @brief  Stack'deki elemanlari ekrana yazar.
  * @param  Stack icin olusturulmus struct yapisi.
  * @retval void
  */
void 			stackDisplay 	(const struct Stack* stack);

#endif /* STACK_H_ */
