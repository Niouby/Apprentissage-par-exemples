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
 * @version 0.0.1 / 2016/01/31
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file character.c
 * @brief
 *
 * Define all the functions related to characters.
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

#ifndef LROW
#define LROW
#include "type_row.h"
#include "function_row.h"
#endif 

#ifndef LRLT
#define LRLT
#include "type_relationship.h"
#include "function_relationship.h"
#endif 

#ifndef LMDL
#define LMDL
#include "type_model.h"
#include "function_model.h"
#endif

/*-----------------------------------------------------------------------*/

/** @brief createEmptyModel
 *
 * Create a empty model
 * @param [void]
 * @return tmp [ptr_model]
 */

ptr_model createEmptyModel(void)
{
	ptr_model tmp=(ptr_model)malloc(sizeof(model));
	tmp->modRelRow = createEmpty();
	return tmp;
}

/** @brief addStereotype
 *
 * Create a empty model
 * @param m [ptr_model m]
 * @param s [ptr_stereotype]
 * @return [void]
 */

void addRelatioship(ptr_model this, ptr_relationship r)
{
	addToRow(this->modRelRow, r);
}

ptr_row getModRelRow(ptr_model this)
{
	return this->modRelRow;
}

void displayModel(ptr_model this)
{
	ptr_row tmp;
	tmp = getExRelRow(this);
	printf("{");
	if (isEmpty(tmp))
	{
		printf("Empty!");
	}
	else 
	{
		while(!isEmpty(tmp))
		{
			printf("[");
			if (isRelationshipOneObject(getData(tmp)))
			{
				displayStereotype(getData1(getData(tmp)));
			}
			else
			{

				displayStereotype(getData1(getData(tmp)));
				if (getRelation(getData(tmp)) == 0)
				{
					printf(" serves ");
				}
				else
				{
					printf(" tracks ");
				}
				displayStereotype(getData2(getData(tmp)));			
			}
			printf("]");
			tmp = nextRow(tmp);
			if (!isEmpty(tmp))
			{
				printf("\n");
			}	
		}
	}
	printf("}");
}