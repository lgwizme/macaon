**Voir aussi :** MacaProAnaphora

# maca\_proanaphora #

Ce module calcule les liens entre un certain nombre de pronoms du français et leurs antécédents. **Le module n'a pas été implémenté.**

## Détails ##

AlejandroAcosta a présenté le 21.11.2006 au groupe anaphores du laboratoire Lattice son idée de spécification pour l'implémentation de ce module.

Points pertinents:
  * Inspiration : Mitkov, Baldwin, Lappin et Leass, ...
  * Le calcul des liens entre les pronoms et leurs antécedents est fondé sur une mesure dite de "saillance" calculée sur les antécedents possibles.
  * La saillence est calculée en fonction d'un ensemble d'heuristiques qui analysent des annotation linguistiques, ou qui prennent en compte d'autres paramettres qui semblent pertinents, par exemple:
    * fonction syntaxique
    * traits morphologiques
    * position dans une structure syntagmatique
    * position dans une structure de dépendance
    * forme fléchi
    * rôle sémantique
    * distance entre l'antécedent et le pronom
    * distance entre le pronom et le début/fin de la phrase
    * contexte de l'antécédent et du pronom (en parenthèse, entre guillemets)
    * ...
  * L'ordre d'application des règles n'est pas important
  * Dans une implémentation qui suit un modèle orienté objet, les règles sont des sous-classes d'une classe abstraite qui contient une méthode "appliquer". Après l'implémentation du coeur du système, les règles peuvent être implémentés séparément, et activées ou déactivées facilement.

Voici un brouillon de l'algorithme central:

```
Ensemble liens, scandidatS, scandidaT, regles
Liste lp, lc, lw
Document doc
Window w
Pronoun pro
Candidate candidat
Rule regle
Score sr

Liste getWindows(Document)
Liste getPronouns(Liste)
Liste getCandidates(Pronoun,Window)
Score calculeScore(Ensemble)
Candidat leBest(Ensemble)

lw = getWindows(doc)
foreach w in lw
{
  lp = getPronouns(w)
  foreach pro in lp
  {
    lc = getCadidates(pro,w)
    foreach cadidat in lc
    {
      foreach regle in regles
      {
        sr = regle.appliquer(doc,candidat,pro,...)
        if (sr.break) break
        else scandaidaT.add(sr)
      }
    }
    scandidatS.add(calculeScore(scandidaT))
  }
  liens.add(pro,leBest(scandidatS))
}   

```