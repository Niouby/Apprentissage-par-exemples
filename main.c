/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 * @author ALONSO Morgane <alonso.morgane@gmail.com>
 *
 * @version 0.0.1 / 25/01/2016
 * @todo
 * @bug #0000 line 320 : Erreur de segmentation (core dumped) after return(0)
 */

/**
 * @file main.c
 * @brief
 *
 * Description, sujet traite
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "type_element.h"
#include "function_element.h"

#include "type_example.h"
#include "function_example.h"

#include "type_model.h"
#include "function_model.h"

#include "comparison.h"

/*----------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
	// Creation of the tree of characters.
	ptr_element personnage=createTheDaddy(1);

	ptr_element force=createSon(2, personnage);
	ptr_element week=createSon(6, personnage);

	ptr_element jedi=createSon(3, force);
	ptr_element sith=createSon(5, force);

	ptr_element council=createSon(4, jedi);

	ptr_element droid=createSon(7, week);
	ptr_element bandi=createSon(10, week);
	ptr_element senator=createSon(12, week);

	ptr_element combat=createSon(8, droid);
	ptr_element pacific=createSon(9, droid);

	ptr_element chasseur=createSon(11, bandi);

	printf("Example 1 :\n");
	ptr_example e1=createExample(senator, 1, 3);
	displayExample(e1);

	printf("Example 2 :\n");
	ptr_example e2=createExample(droid, 5, 2);
	displayExample(e2);

	printf("Example 3 :\n");
	ptr_example e3=createExample(jedi, 4, 2);
	displayExample(e3);

	printf("\nModel initialization...\n\n");
	
	ptr_model model;
	model=initModel(e1);
	displayModel(model);
	
	printf("Comparison between model and example 2...\n");
	comparison(model, e2);
	displayModel(model);

	printf("Comparison between model and example 3...\n");
	comparison(model, e3);
	displayModel(model);

	return 0;
}
// typedef enum elements {personnage,force,jedi,conseil,sith,samedi,dimanche} Jour_de_Semaine;
