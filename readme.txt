INTRODUCTION
While artificial languages (like programming languages) and natural languages share features of organization and structure, natural languages contain far more variety and many more exceptions. Nonetheless, we can apply ideas of parsing derived from computing to sentences in natural languages such as English.
The goal here is to use augmented transition networks to parse a limited range of declarative English sentences, based on the lexicon and other tables in our text.

THE PROJECT
Write and test a program that reads declarative English sentences and produces LISP-like parses of those sentences. The sentences will consist of a noun phrase (subject), a verb phrase, and any of: noun phrases for direct and indirect objects, adjectives, adverbs, and prepositional phrases, as in the examples in class.
The vocabulary in your sentences need not be any larger than in the text's tables, though you can extend that lexicon if you like. Parse the sentences with augmented transition networks.

EXAMPLE
A run of the program might look like this:
		
		Enter a sentence: Alice gave Bob a picture of the boat.
		
		(S (MOOD declarative)
		   (SUBJ (NP (NAME Alice)
		             (NUM 3s)))
		   (VERB (V (VERB give)
		            (TENSE past)
		            (NUM 3s)))
		   (IND-OBJ (NP (NAME Bob)
		                (NUM 3s)))
		   (OBJ (NP (DET a)
		            (NOUN picture)
                            (NUM 3s))
                            (MODS (PP (PREP of)
			              (OBJ (NP (DET the)
		                           (NOUN boat)
		                           (NUM 3s)))))))