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
 * @version 0.0.1 / 2016/01/25
 * @todo #0000
 * @bug #0000 [FIXED] : line 320 : Erreur de segmentation (core dumped)
 * after return(0).
 */

/**
 * @file main.c
 * @brief
 *
 * Main file of the project. It contains the benchmark of the project.
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

#ifndef LTREE
#define LTREE
#include "type_tree.h"
#include "function_tree.h"
#endif 

#ifndef LROW
#define LROW
#include "type_row.h"
#include "function_row.h"
#endif 

#ifndef LCHR
#define LCHR
#include "type_character.h"
#include "function_character.h"
#endif 

#ifndef LSTR
#define LSTR
#include "type_stereotype.h"
#include "function_stereotype.h"
#endif 

#ifndef LRLT
#define LRLT
#include "type_relationship.h"
#include "function_relationship.h"
#endif 

#ifndef LEXP
#define LEXP
#include "type_example.h"
#include "function_example.h"
#endif 

#ifndef LMDL
#define LMDL
#include "type_model.h"
#include "function_model.h"
#endif

#ifndef COMP
#define COMP
#include "comparison.h"
#endif 
 
#ifndef CLASS
#define CLASS
#include "class.h"
#endif 

#define SETVERT printf("\e[32m");
#define SETJAUNE printf("\e[33m");
#define SETBLANC printf("\e[0m");
#define SETROUGE printf("\e[31m");
#define SETBLEU printf("\e[34m");

/*-----------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
	char checkpoint;
	int vilain, neutral, kind, good;

	/* Definition of alignments : */
	vilain=1;
	neutral=2;
	kind=3;
	good=4;

	/* Creation of the tree of characters : */
	initClass();
	SETVERT
	printf("Initialization of characters :\n");
	SETBLANC
	ptr_character c1=createCharacter(sith, 2, vilain);
	displayCharacter(c1);
	printf("\n");
	ptr_character c2=createCharacter(council, 4, good);
	displayCharacter(c2);
	printf("\n");
	ptr_character c3=createCharacter(jedi, 3, kind);
	displayCharacter(c3);
	printf("\n");
	ptr_character c4=createCharacter(council, 4, neutral);
	displayCharacter(c4);
	printf("\n");

	/*-------------------------------------------------------------------*/
	/*                                TEST 1                             */
	/*-------------------------------------------------------------------*/

	SETVERT
	printf("Preparing some stereotypes...\n");
	ptr_stereotype s1;
	s1 = initStereotype(c1);
	ptr_stereotype s2;
	s2 = initStereotype(c2);

	printf("Preparing the examples...\n");
	ptr_example e1;
	e1 = createEmptyExample();
	addFirstCharacter(e1, c1);
	ptr_example e2;
	e2 = createEmptyExample();
	addFirstCharacter(e2, c1);
	addSecondCharacter(e2, c2, 0);
	ptr_example e3;
	e3 = createEmptyExample();
	addFirstCharacter(e3, c1);
	addSecondCharacter(e3, c2, 1);

	printf("Preparing the models...\n");
	SETJAUNE
	ptr_relationship r1;
	r1 = createRelationshipOneObject(s1);
	ptr_model m1 = createEmptyModel();
	addRelatioship(m1, r1);
	ptr_relationship r2;
	r2 = createRelationshipOneObject(s1);
	ptr_model m2 = createEmptyModel();
	addRelatioship(m2, r2);
	ptr_relationship r3;
	r3 = createRelationship(s1, s2, 0);
	ptr_model m3 = createEmptyModel();
	addRelatioship(m3, r3);
	ptr_relationship r4;
	r4 = createRelationship(s1, s2, 0);
	ptr_model m4 = createEmptyModel();
	addRelatioship(m4, r4);
	ptr_relationship r5;
	r5 = createRelationship(s1, s2, 0);	
	ptr_model m5 = createEmptyModel();
	addRelatioship(m5, r5);
	
	printf("L'exemple : \n");
	displayExample(e1);
	printf("\n\n");

	printf("Le modèle : \n");
	displayModel(m1);
	printf("\n\n");
	SETBLANC
	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);

	/* Main function of the project. */
	SETJAUNE
	printf("Comparing the example with the model...\n");
	SETBLANC
	compEM(e1, m1);
	printf("La nouvelle liste de modèles après toutes les comparaisons :\n");
	displayModel(m1);
	printf("\n");

	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);
	SETJAUNE
	printf("L'exemple : \n");
	displayExample(e2);
	printf("\n\n");

	printf("Le modèle : \n");
	displayModel(m2);
	printf("\n\n");
	SETBLANC
	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);

	/* Main function of the project. */
	SETJAUNE
	printf("Comparing the example with the model...\n");
	SETBLANC
	compEM(e2, m2);
	printf("La nouvelle liste de modèles après toutes les comparaisons :\n");
	displayModel(m2);
	printf("\n");

	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);	
	SETJAUNE
	printf("L'exemple : \n");
	displayExample(e1);
	printf("\n\n");

	printf("Le modèle : \n");
	displayModel(m3);
	printf("\n\n");
	SETBLANC
	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);

	/* Main function of the project. */
	SETJAUNE
	printf("Comparing the example with the model...\n");
	SETBLANC
	compEM(e1, m3);
	printf("La nouvelle liste de modèles après toutes les comparaisons :\n");
	displayModel(m3);
	printf("\n");

	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);
	SETJAUNE	
	printf("L'exemple : \n");
	displayExample(e2);
	printf("\n\n");

	printf("Le modèle : \n");
	displayModel(m4);
	printf("\n\n");
	SETBLANC
	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);

	/* Main function of the project. */
	SETJAUNE
	printf("Comparing the example with the model...\n");
	SETBLANC
	compEM(e2, m4);
	printf("La nouvelle liste de modèles après toutes les comparaisons :\n");
	displayModel(m4);
	printf("\n");
	
	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);
	SETJAUNE
	printf("L'exemple : \n");
	displayExample(e3);
	printf("\n\n");

	printf("Le modèle : \n");
	displayModel(m5);
	printf("\n\n");
	SETBLANC
	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);

	/* Main function of the project. */
	SETJAUNE
	printf("Comparing the example with the model...\n");
	SETBLANC
	compEM(e3, m5);
	printf("La nouvelle liste de modèles après toutes les comparaisons :\n");
	displayModel(m5);
	printf("\n");
	return 0;
}
