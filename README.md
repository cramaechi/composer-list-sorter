# Composer List Sorter
A program that reads in a numbered list of song titles wherein each line contains the song
title and composer of that title. The program then produces an alphabetized list of composers
followed by list of pieces by them alphabetized on the title within composer.

### Synopsis
This program reads in a numbered list consisting of lines containing the name, then composers
of that title, one per line. The composer name may be only last name, or an initial and one
name, or two name: first_name last_name, or three names: first_name middle_name last_name.

There may be a few tunes with "no author listed" as composer name. In the subsequent 
processing, "no author listed" should not be rearranged. 

Here is a very abbreiviated list of the titles and composers:

1. Adagio “MoonLight” Sonata - Ludwig Van Beethoven 2. An Alexis - F.H. Hummel and J.N. Hummel
3. A La Bien Aimee- Ben Schutt
4. At Sunset- E. MacDowell
5. Angelus- J. Massenet
6. Anitra’s Dance- Edward Grieg 7. Ase’s Death- Edward Grieg
8. Au Matin- Benj. - Godard
...

37. The Dying Poet - L. Gottschalk
38. Dead March - G.F. Handel
39. Do They Think of Me At Home - Chas. W. Glover 40. The Dearest Spot - W.T. Wrighton
1. Evening - L. Van Beethoven
2. Embarrassment - Franz Abt
3. Erin is my Home - no author listed
4. Ellen Bayne - Stephen C. Foster
.. .
9. Alla Mazurka- A. Nemerowsky
.. .
1. The Dying Volunteer - A.E. Muse
2. Dolly Day - Stephen C. Foster
3. Dolcy Jones - Stephen C. Foster
4. Dickory, Dickory, Dock - no author listed
5. The Dear Little Shamrock - no author listed
6. Dutch Warbler - no author listed
...

The programs job is to produce an alphabetized list of composers followed by list of pieces
by them alphabetized on the title within composer.

**The list of song titles is already saved in the program.**

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/composer-list-sorter.git
   ```
    or [download as ZIP](https://github.com/cramaechi/composer-list-sorter/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd composer-list-sorter
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./list_sorter
```

Sample Output:
```
Alphabetized list of composers/song titles
------------------------------------------

Abt Franz - Embarrassment  

Beethoven Ludwig Van - Adagio "MoonLight" Sonata  

Beethoven L. Van - Evening  

Foster Stephen C. - Ellen Bayne  

Foster Stephen C. - Dolly Day  

Foster Stephen C. - Dolcy Jones  

Glover Chas. W. - Do They Think of Me At Home  

Godard - Au Matin  Benj.  

Gottschalk L. - Dying Poet, The  

Grieg Edward - Anitra's Dance  

Grieg Edward - Ase's Death  

Handel G.F. - Dead March  

Hummel F.H. Hummel and J.N. - Alexis, An  

MacDowell E. - At Sunset  

Massenet J. - Angelus  

Muse A.E. - Dying Volunteer, The  

Nemerowsky A. - Alla Mazurka  

Schutt Ben - La Bien Aimee, A  

Wrighton W.T. - Dearest Spot, The  

no author listed - Erin is my Home  

no author listed - Dickory, Dickory, Dock  

no author listed - Dear Little Shamrock, The  

no author listed - Dutch Warbler 
```
