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
 * @file type_example.h
 * @brief
 *
 * This file describes the "example" type.
 */

/*-----------------------------------------------------------------------*/

/** @brief example
 *
 * "example" structure's definition. Examples will be compared to a model
 * (see the model folder). An example(i.e. a character) is composed of a
 * type, an influence and an alignment.
 * @field type [element*]
 * @field influence [int]
 * @field alignment [int]
 * @name example
 * @pointer ptr_example
 */

typedef struct example
{
	struct element* type;
	int influence;
	int alignment;
}example, *ptr_example;
