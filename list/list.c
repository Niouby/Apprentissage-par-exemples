/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * This file is the work of students from Polytech Marseille. It can not be
 * reproduced, modified or used without the express opinion of its authors.
 */

/**
 * @author ALONSO Morgane <alonso.morgane@gmail.com>
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 *
 * @version 0.0.1 / 2016/02/13
 * @todo #0000 [] Adapt functions to models and characters.
 * @bug #0000 []
 */

/**
 * @file list.c
 * @brief
 *
 * This file describes all the functions related to lists.
 */

/*-----------------------------------------------------------------------*/

#ifndef LSTDIO
#define LSTDIO
#include <stdio.h>
#endif 

#ifndef LSTDLIB
#define LSTDLIB
#include <stdlib.h>
#endif 

#ifndef LLIST
#define LLIST
#include "type_list.h"
#include "function_list.h"
#endif 


/*-----------------------------------------------------------------------*/

/** @brief createEmpty
 *
 * Create the empty list.
 * @param [void]
 * @return NULL [ptr_list]
 */

ptr_list createEmpty(void)
{
	return NULL;
}

/** @brief isEmpty
 *
 * Tell if the list is empty.
 * @param list [ptr_list]
 * @return empty [int]
 */

int isEmpty(ptr_list list)
{
	int empty=0;
	if(list==NULL)
	{
		empty=1;
	}
	return(empty);
}

/** @brief addToList
 *
 * Add the element to the list.
 * @param list [ptr_list]
 * @param element [void*]
 * @return tmp [ptr_list]
 */

ptr_list addToList(ptr_list list, void *element)
{
	ptr_list tmp;
	tmp=(ptr_list)malloc(sizeof(list));
	tmp->data=element;
	tmp->next=list;
	return tmp;
}

/** @brief headList
 *
 * Give the data of the first list of the list.
 * @param list [ptr_list]
 * @return list->data [void*]
 */

void* headList(ptr_list list)
{
	return list->data;
}

/** @brief nextList
 *
 * Give the following list of the list.
 * @param list [ptr_list]
 * @return list->next [ptr_list]
 */

ptr_list nextList(ptr_list list)
{
	list=list->next;
	
	return list;
}

/** @brief displayList
 *
 * Display the elements of the list.
 * @param list [ptr_list]
 * @return [void]
 */


/** @brief lengthList
 *
 * Calculate the length of the list.
 * @param list [ptr_list]
 * @return length [int]
 */

int lengthList(ptr_list list)
{
	int length;

	length=0;
	while(list!=NULL)
	{
		list=list->next;
		length++;
	}
	return length;
}

/** @brief copyListAux
 *
 * copyList's auxiliary function.
 * @param list [ptr_list]
 * @return copiedList [ptr_list]
 */

ptr_list copyListAux(ptr_list list)
{
	ptr_list copiedList;

	copiedList=createEmpty();
	while(list!=NULL)
	{
		copiedList=addToList(copiedList, list->data);
		list=list->next;
	}
	return copiedList;
}

/** @brief copyList
 *
 * Give a copy of the list.
 * @param list [ptr_list]
 * @return copiedList [ptr_list]
 */

ptr_list copyList(ptr_list list)
{
	ptr_list copiedList;

	copiedList=copyListAux(list);
	copiedList=copyListAux(copiedList);
	return copiedList;
}

/** @brief searchListe
 *
 * Tell if an element is in the list or not. If it is, the function will
 * return a list with this element as first list, otherwise, it will return
 * the empty list.
 * @param list [ptr_list]
 * @param element [void*]
 * @return list [ptr_list]
 */

ptr_list searchList(ptr_list list, void *element)
{
	int found;

	found=0;
	while(list!=NULL && found==0)
	{
		if(list->data==element)
		{
			found=1;
		}
		else
		{
			list=list->next;
		}
	}
	return list;
}

/** @brief delete
 *
 * Delete an element of the list, if possible.
 * @param list [ptr_list]
 * @param element [void*]
 * @return list [ptr_list]
 */

ptr_list delete(ptr_list list, void *element)
{
	ptr_list previous, copiedList;

	previous=list;
	copiedList=list;
	while(copiedList!=NULL && copiedList->data!=element)
	{
		previous=copiedList;
		copiedList=copiedList->next;
	}
	if(copiedList!=NULL)
	{
		if(copiedList==list)
		{
			list=list->next;
		}
		else
		{
			previous->next=copiedList->next;
		}
	}
	return list;
}

/** @brief getElementI
 *
 * Give the element at the position i
 * @param list [ptr_list]
 * @param n [int]
 * @return tmp->data [void*]
 */

ptr_list getElementI(ptr_list l, int n)
{
	ptr_list tmp = l;
	int i;
	for (i = 0; i < n; i++)
	{
		tmp = nextList(tmp);
	}
	return headList(tmp);
}
