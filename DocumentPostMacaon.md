# Introduction #

Voici un exemple de la structure d'un document tratité par Macaon.


# Entrée #

Etant donné le document [exemple-0.1.txt](http://www.linguist.jussieu.fr/~aacosta/macaon/exemples/exemple-0.1.txt):

```
C'est un petit document. Il est bref et il a été écrit vers 18h, le 24 novembre 2006 par Alejandro Acosta.
```

# Commande #

Le document peut être analysé avec la séquence des modules Macaon inclus dans la commande suivante :

```
$cat exemple-0.1.txt |
maca_segmenter -x |
maca_tokenizer |
maca_nematcher |
maca_lexer -i - |
maca_hmm_tagger -i - |
maca_anamorph -i - |
maca_chunker -o exemple-0.1.xml
```

# Sortie #

Le résultat serait [exemple-0.1.xml](http://www.linguist.jussieu.fr/~aacosta/macaon/exemples/exemple-0.1.xml) (si vous avez des problèmes pour visualiser ce fichier, essayez avec un navigateur comme Firefox).

NB. Bien que des modules pour la resolution des liens anaphoriques et de coréférence n'ont toujours pas été implémentés, il nous semble utile d'inclure dans cet exemple la représentation des liens anaphoriques (ajoutée à la main).

```
<?xml version='1.0' encoding='UTF-8'?>
<document filename='exemple-0.1.txt'>
  <meta>
    <maca_stamps>
      <maca_stamp timestamp='Fri Nov 24 18:57:23 2006' version='2.3' module='maca_segmenter'/>
      <maca_stamp timestamp='Fri Nov 24 18:57:23 2006' version='1.1' module='maca_tokenizer'/>
      <maca_stamp timestamp='Fri Nov 24 18:57:23 2006' version='1.4.2' module='maca_nematcher'/>
      <maca_stamp timestamp='Mon Nov 27 18:24:13 2006' version='0.3' module='maca_lexer'/>
      <maca_stamp timestamp='Mon Nov 27 18:24:13 2006' version='0.4' module='maca_hmm_tagger'/>
      <maca_stamp timestamp='Mon Nov 27 18:30:54 2006' version='2.3b' module='maca_chunker'/>
    </maca_stamps>
    <universe>
      <referents>
        <referent type='typeY' external_id='DOCUMENT_exemple-0.1.txt' id='r1'/>
        <referent type='typeX' external_id='SOME_HUMAN_K42354' id='r2'/>
      </referents>
      <reference_links>
        <ref_link source='sn1p1s2_chk1' antecedent='sn1p1s1_chk5' type='pronominal_anaphora' id='l1' referent='r1'/>
        <ref_link source='sn1p1s2_chk8' antecedent='sn1p1s2_chk2' type='pronominal_anaphora' id='l2' referent='r1'/>
      </reference_links>
    </universe>
  </meta>
  <contents>
    <body>
      <section analyze='yes'>
        <paragraph id='sn1p1'>
          <sentence id='sn1p1s1'>
            <text>C'est un petit document.</text>
            <tokens count='9'>
              <token type='wtoken' id='sn1p1s1_T1'>C'</token>
              <token type='wtoken' id='sn1p1s1_T2'>est</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s1_T3'>un</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s1_T4'>petit</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s1_T5'>document</token>
              <token type='sponct' id='sn1p1s1_T6'>.</token>
            </tokens>
            <words>
              <word lex_id='50668' id='sn1p1s1_W1'>
                <form>C'</form>
                <pos type='cln'/>
              </word>
              <word lex_id='161536' id='sn1p1s1_W2'>
                <form>est</form>
                <pos type='v'/>
              </word>
              <word lex_id='391366' id='sn1p1s1_W3'>
                <form>un</form>
                <pos type='det'/>
              </word>
              <word lex_id='278527' id='sn1p1s1_W4'>
                <form>petit</form>
                <pos type='adj'/>
              </word>
              <word lex_id='129793' id='sn1p1s1_W5'>
                <form>document</form>
                <pos type='nc'/>
              </word>
              <word lex_id='28' id='sn1p1s1_W6'>
                <form>.</form>
                <pos type='ponctw'/>
              </word>
            </words>
            <chunks>
              <chunk head_word='sn1p1s1_W1' head='sn1p1s1_chk2' height='1' words='sn1p1s1_W1' type='GN' id='sn1p1s1_chk1'>
                <chunk head_word='sn1p1s1_W1' type='cln' id='sn1p1s1_chk2' words='sn1p1s1_W1' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s1_W2' head='sn1p1s1_chk4' height='1' words='sn1p1s1_W2' type='GVf' id='sn1p1s1_chk3'>
                <chunk head_word='sn1p1s1_W2' type='v' id='sn1p1s1_chk4' words='sn1p1s1_W2' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s1_W5' head='sn1p1s1_chk9' height='2' words='sn1p1s1_W3 sn1p1s1_W4 sn1p1s1_W5' type='GN' id='sn1p1s1_chk5'>
                <chunk head_word='sn1p1s1_W3' type='det' id='sn1p1s1_chk6' words='sn1p1s1_W3' height='0'/>
                <chunk head_word='sn1p1s1_W4' head='sn1p1s1_chk8' height='1' words='sn1p1s1_W4' type='GADJ' id='sn1p1s1_chk7'>
                  <chunk head_word='sn1p1s1_W4' type='adj' id='sn1p1s1_chk8' words='sn1p1s1_W4' height='0'/>
                </chunk>
                <chunk head_word='sn1p1s1_W5' type='nc' id='sn1p1s1_chk9' words='sn1p1s1_W5' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s1_W6' type='ponctw' id='sn1p1s1_chk10' words='sn1p1s1_W6' height='0'/>
            </chunks>
          </sentence>
          <sentence id='sn1p1s2'>
            <text>Il est bref et il a été écrit vers 18h, le 24 novembre 2006 par Alejandro Acosta.</text>
            <tokens count='35'>
              <token type='wtoken' id='sn1p1s2_T1'>Il</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T2'>est</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T3'>bref</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T4'>et</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T5'>il</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T6'>a</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T7'>été</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T8'>écrit</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T9'>vers</token>
              <token type='space'/>
              <token type='timex-chrono' id='sn1p1s2_T10'>18h</token>
              <token type='wponct' id='sn1p1s2_T11'>,</token>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T12'>le</token>
              <token type='space'/>
              <ne type='date/dmy' pos='nc'>
                <token type='cardinal' id='sn1p1s2_T13'>24</token>
                <token type='space'/>
                <token type='wtoken' id='sn1p1s2_T14'>novembre</token>
                <token type='space'/>
                <token type='cardinal' id='sn1p1s2_T15'>2006</token>
              </ne>
              <token type='space'/>
              <token type='wtoken' id='sn1p1s2_T16'>par</token>
              <token type='space'/>
              <ne type='name/fl' pos='np'>
                <token type='wtoken' id='sn1p1s2_T17'>Alejandro</token>
                <token type='space'/>
                <token type='wtoken' id='sn1p1s2_T18'>Acosta</token>
              </ne>
              <token type='sponct' id='sn1p1s2_T19'>.</token>
            </tokens>
            <words>
              <word lex_id='205231' id='sn1p1s2_W1'>
                <form>Il</form>
                <pos type='cln'/>
              </word>
              <word lex_id='161536' id='sn1p1s2_W2'>
                <form>est</form>
                <pos type='v'/>
              </word>
              <word lex_id='47100' id='sn1p1s2_W3'>
                <form>bref</form>
                <pos type='adv'/>
              </word>
              <word lex_id='162281' id='sn1p1s2_W4'>
                <form>et</form>
                <pos type='coo'/>
              </word>
              <word lex_id='205231' id='sn1p1s2_W5'>
                <form>il</form>
                <pos type='cln'/>
              </word>
              <word lex_id='49' id='sn1p1s2_W6'>
                <form>a</form>
                <pos type='v'/>
              </word>
              <word lex_id='162971' id='sn1p1s2_W7'>
                <form>été</form>
                <pos type='vppart'/>
              </word>
              <word lex_id='136906' id='sn1p1s2_W8'>
                <form>écrit</form>
                <pos type='vppart'/>
              </word>
              <word lex_id='396775' id='sn1p1s2_W9'>
                <form>vers</form>
                <pos type='prep'/>
              </word>
              <word lex_id='0' id='sn1p1s2_W11'>
                <form>18h</form>
                <pos type='np'/>
              </word>
              <word lex_id='16' id='sn1p1s2_W12'>
                <form>,</form>
                <pos type='ponctw'/>
              </word>
              <word lex_id='227361' id='sn1p1s2_W13'>
                <form>le</form>
                <pos type='det'/>
              </word>
              <word lex_id='0' type='ne' id='sn1p1s2_W15' ne-type='date/dmy'>
                <pos type='nc'/>
                <form>24 novembre 2006</form>
              </word>
              <word lex_id='270514' id='sn1p1s2_W16'>
                <form>par</form>
                <pos type='prep'/>
              </word>
              <word lex_id='0' type='ne' id='sn1p1s2_W18' ne-type='name/fl'>
                <pos type='np'/>
                <form>Alejandro Acosta</form>
              </word>
              <word lex_id='28' id='sn1p1s2_W19'>
                <form>.</form>
                <pos type='ponctw'/>
              </word>
            </words>
            <chunks>
              <chunk head_word='sn1p1s2_W1' head='sn1p1s2_chk2' height='1' words='sn1p1s2_W1' type='GN' id='sn1p1s2_chk1'>
                <chunk head_word='sn1p1s2_W1' type='cln' id='sn1p1s2_chk2' words='sn1p1s2_W1' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s2_W2' head='sn1p1s2_chk4' height='1' words='sn1p1s2_W2' type='GVf' id='sn1p1s2_chk3'>
                <chunk head_word='sn1p1s2_W2' type='v' id='sn1p1s2_chk4' words='sn1p1s2_W2' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s2_W3' head='sn1p1s2_chk6' height='1' words='sn1p1s2_W3' type='GADV' id='sn1p1s2_chk5'>
                <chunk head_word='sn1p1s2_W3' type='adv' id='sn1p1s2_chk6' words='sn1p1s2_W3' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s2_W4' type='coo' id='sn1p1s2_chk7' words='sn1p1s2_W4' height='0'/>
              <chunk head_word='sn1p1s2_W5' head='sn1p1s2_chk9' height='1' words='sn1p1s2_W5' type='GN' id='sn1p1s2_chk8'>
                <chunk head_word='sn1p1s2_W5' type='cln' id='sn1p1s2_chk9' words='sn1p1s2_W5' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s2_W8' head='sn1p1s2_chk13' height='1' words='sn1p1s2_W6 sn1p1s2_W7 sn1p1s2_W8' type='GVf' id='sn1p1s2_chk10'>
                <chunk head_word='sn1p1s2_W6' type='v' id='sn1p1s2_chk11' words='sn1p1s2_W6' height='0'/>
                <chunk head_word='sn1p1s2_W7' type='vppart' id='sn1p1s2_chk12' words='sn1p1s2_W7' height='0'/>
                <chunk head_word='sn1p1s2_W8' type='vppart' id='sn1p1s2_chk13' words='sn1p1s2_W8' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s2_W11' head='sn1p1s2_chk16' height='2' words='sn1p1s2_W9 sn1p1s2_W11' type='GP' id='sn1p1s2_chk14'>
                <chunk head_word='sn1p1s2_W9' type='prep' id='sn1p1s2_chk15' words='sn1p1s2_W9' height='0'/>
                <chunk head_word='sn1p1s2_W11' head='sn1p1s2_chk17' height='1' words='sn1p1s2_W11' type='GN' id='sn1p1s2_chk16'>
                  <chunk head_word='sn1p1s2_W11' type='np' id='sn1p1s2_chk17' words='sn1p1s2_W11' height='0'/>
                </chunk>
              </chunk>
              <chunk head_word='sn1p1s2_W12' type='ponctw' id='sn1p1s2_chk18' words='sn1p1s2_W12' height='0'/>
              <chunk head_word='sn1p1s2_W15' head='sn1p1s2_chk21' height='1' words='sn1p1s2_W13 sn1p1s2_W15' type='GN' id='sn1p1s2_chk19'>
                <chunk head_word='sn1p1s2_W13' type='det' id='sn1p1s2_chk20' words='sn1p1s2_W13' height='0'/>
                <chunk head_word='sn1p1s2_W15' type='nc' id='sn1p1s2_chk21' words='sn1p1s2_W15' height='0'/>
              </chunk>
              <chunk head_word='sn1p1s2_W18' head='sn1p1s2_chk24' height='2' words='sn1p1s2_W16 sn1p1s2_W18' type='GP' id='sn1p1s2_chk22'>
                <chunk head_word='sn1p1s2_W16' type='prep' id='sn1p1s2_chk23' words='sn1p1s2_W16' height='0'/>
                <chunk head_word='sn1p1s2_W18' head='sn1p1s2_chk25' height='1' words='sn1p1s2_W18' type='GN' id='sn1p1s2_chk24'>
                  <chunk head_word='sn1p1s2_W18' type='np' id='sn1p1s2_chk25' words='sn1p1s2_W18' height='0'/>
                </chunk>
              </chunk>
              <chunk head_word='sn1p1s2_W19' type='ponctw' id='sn1p1s2_chk26' words='sn1p1s2_W19' height='0'/>
            </chunks>
          </sentence>
        </paragraph>
      </section>
    </body>
  </contents>
</document>
```








