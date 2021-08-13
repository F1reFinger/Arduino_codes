
const int buzzerPin = 8;

// We'll set up an array with the notes we want to play
// change these values to make different songs!

// Length must equal the total number of notes and spaces 

const int songLength = 102;

// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone)

char notes[] = "gecegCEDCe#gggEDCbabCCgecgecegCEDCe#gggEDCbabCCgecEEEFGGFEDEFFFEDCbabCe#ggCCCbaaaDFEDCCbggCDEFGCDEFDC "; // a space represents a rest

// Beats is an array of values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.

int beats[] = {3, 1, 4, 4, 4, 8, 3, 1, 4, 4, 4, 8, 2, 2, 6, 2, 4, 8, 3, 1, 4, 4, 4, 4, 8, 3,
1, 4, 4, 4, 8, 3, 1, 4, 4, 4, 8, 2, 2, 6, 2, 4, 8, 3, 1, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4, 8, 2,
2, 4, 4, 4, 8, 4, 6, 2, 4, 8, 3, 1, 6, 4, 4, 8, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4,
2, 2, 6, 2, 2, 2, 8, 2, 2, 6, 2, 4, 8, 1};

// The tempo is how fast to play the song.
// To make the song play faster, decrease this value.

int tempo = 150;


void setup() 
{
  pinMode(buzzerPin, OUTPUT);
}


void loop() 
{
  int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats * tempo;  // length of note/rest in ms
    
    if (notes == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  
  // We only want to play the song once, so we'll pause forever:
 // while(true){}
  // If you'd like your song to play over and over,
  // remove the above statement
}


int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.
  
  int i;
  const int numNotes = 15;  // number of notes we're storing
  
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', '#', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B' };
  int frequencies[] = {262, 294, 330, 349, 370, 392, 440, 494, 523, 587, 659, 699, 784, 880, 989};
  
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names == note)         // Is this the one?
    {
      return(frequencies);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}
