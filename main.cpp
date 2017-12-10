//A program that sorts a line in alphabetical order.
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void removeLeadingNumbers(string& line);
//Precondition: mList is has been preloaded with a line of music 
//titles and the composers.
//Postcondition: Removes leading numbers, any periods, and any
//spaces before the music title.

void compressSpaces(string& line);
//Precondition: mList is non-empty.
//Postcondition: Replaces consecutive spaces with a single space.

void removeDashes(string& line);
//Precondition: mList is non-empty.
//Postcondition: Replaces all dashes in every music title with a space.

void addSpace(string& line);
//Precondition: mList is non-empty.
//Postcondition: Inserts a space between the last word in the title and
//the '-' character.

void moveArticles(string& line);
//Precondition: mList is non-empty.
//Postcondition: Moves initial words, "A", "An", and "The", to just 
//before the dash character preceding the composer name. 

void moveComposerNames(string& line);
//Precondition: mList is non-empty.
//Postcondition: Moves all composer names to the beginning of each line,
//followed by a dash character, followed by the music title.

void interchangeComposerNames(string& line);
//Precondition: mList is non-empty.
//Postcondition: Moves any first initial, first and second names of the
//composer to after the composer's last name.

void sort(string mList[], int startPos, int endPos);
//Precondition: mList is non-empty.
//Postcondition: Sorts mList in alphabetical order using the merge sort
//algorithm.

void reformat(string mList[], int size);
//Precondition: mList is non-empty.
//Postcondition: Sorts the line in alphabetical order.

void output(string mList[], int size);
//Precondition: mList is non-empty.
//Postcondition: Prints out the music list in alphabetical order.

const int MAX = 23;  

int main()
{
    string musicList[MAX] = {
        "1. Adagio \"MoonLight\" Sonata - Ludwig Van Beethoven",
        "2. An    Alexis - F.H. Hummel and J.N. Hummel", 
        "3. A La    Bien Aimee - Ben Schutt",
        "4. At    Sunset -    E. MacDowell",
        "5. Angelus - J. Massenet",
        "6. Anitra's Dance - Edward Grieg",
        "7. Ase's Death - Edward Grieg",
        "8. Au Matin- Benj.- Godard",
        "9. The Dying Poet - L. Gottschalk",
        "10. Dead March - G.F. Handel",
        "11. Do They Think of Me At Home - Chas. W. Glover",
        "12. The Dearest Spot - W.T. Wrighton",
        "13. Evening - L. Van Beethoven",
        "14. Embarrassment - Franz Abt",
        "15. Erin is my Home - no author listed",
        "16. Ellen Bayne - Stephen C. Foster",
        "17. Alla Mazurka - A. Nemerowsky",
        "18. The Dying Volunteer - A.E. Muse",
        "19. Dolly Day - Stephen C. Foster",
        "20. Dolcy Jones- Stephen C. Foster",
        "21. Dickory, Dickory, Dock - no author listed",
        "22. The Dear Little Shamrock - no author listed",
        "23. Dutch Warbler- no author listed"};

    reformat(musicList, MAX);
    output(musicList, MAX);

    return 0;
}

void sort(string mList[], int startPos, int endPos)
{
    if (endPos - startPos <= 1)
        return;

    sort(mList, startPos, (startPos + endPos) / 2);
    sort(mList, ((startPos + endPos) / 2) + 1, endPos);

    for (int i = 1; i < endPos; i++)
    {
        string l1 = mList[i].substr(0, mList[i].find(" ") - 1);
        string l2 = mList[i - 1].substr(0, mList[i - 1].find(" ") - 1);
        int j = i;

        while (j > 0 && l1 < l2)
        {
            string temp = mList[j - 1];
            mList[j - 1] = mList[j];
            mList[j] = temp;

            j--;
            l1 = mList[j].substr(0, mList[j].find(" ") - 1);
            l2 = mList[j - 1].substr(0, mList[j - 1].find(" ") - 1);
        }
    }
}

void interchangeComposerNames(string& line)
{
    if (line.find("no author listed") == -1)
    {
        int pos = line.find("-");
        pos = line.find_last_of(" ", pos - 2);

        if (pos >= 0)
        {
            string halfOfName = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find("-");
            line.insert(pos, halfOfName + " ");
        }
    }
}

void moveComposerNames(string& line)
{
    int pos = line.find("-"), sSize = line.length();
    string composer = line.substr(pos + 2, sSize - (pos + 2));
    line.erase(pos + 2, sSize - (pos + 2));
    line.insert(0, composer + " - ");
    line.erase(line.rfind("-"), 1);
}

void moveArticles(string& line)
{
    int pos;
    if ((pos = line.find("A ")) >= 0)
    {
        line.erase(pos, 2);
        pos = line.find("-");
        line.insert(pos, "A ");
        pos = line.find("-");
        line.insert(pos - 3, ",");
    }
    else if ((pos = line.find("An ")) >= 0)
    {
        line.erase(pos, 3);
        pos = line.find("-");
        line.insert(pos, "An ");
        pos = line.find("-");
        line.insert(pos - 4, ",");
    }
    else if ((pos = line.find("The ")) >= 0)
    {
        line.erase(pos, 4);
        pos = line.find("-");
        line.insert(pos, "The ");
        pos = line.find("-");
        line.insert(pos - 5, ",");
    }
}

void addSpace(string& line)
{
    int pos = line.find("-");
    if (!isspace(line[pos - 1]))
        line.insert(pos, " ");
}

void removeDashes(string& line)
{
    int lastOccurence = line.rfind("-");
    for (int i = 0; i < lastOccurence; i++)
    {
        if (line[i] == '-')
            line.replace(i, 1, " ");
    }
}

void compressSpaces(string& line)
{
    for (int i = line.length() - 1; i > 0; i--)
    {
        if (isspace(line[i]) && isspace(line[i - 1]))
            line.erase(i, 1);
    }
}

void removeLeadingNumbers(string& line)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    line.erase(0, line.find_first_of(alphabet));
}

void reformat(string mList[], int size)
{
    for (int i = 0; i < size; i++)
    {
        removeLeadingNumbers(mList[i]);
        compressSpaces(mList[i]);
        removeDashes(mList[i]);
        addSpace(mList[i]);
        moveArticles(mList[i]);
        moveComposerNames(mList[i]);
        interchangeComposerNames(mList[i]);
    }

    sort(mList, 0, size - 1);
}

void output(string mList[], int size)
{
    cout<<"\nAlphabetized list of composers/song titles\n";
    cout<<"------------------------------------------\n\n";
    for (int i = 0; i < size; i++)
        cout<<mList[i]<<endl<<endl;
}
