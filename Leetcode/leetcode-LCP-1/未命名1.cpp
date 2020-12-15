int game(int* guess, int guessSize, int* answer, int answerSize){
    int count = 0;
    int i = guessSize;
    while( i-->0 )
    {
        if(guess[i] == answer[i])
            count++;
    }
    return count;
}
