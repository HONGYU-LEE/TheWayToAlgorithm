int* distributeCandies(int candies, int num_people, int* returnSize){

    int *child = (int*)malloc(num_people * sizeof(int));
    memset(child, 0, num_people * sizeof(int));
    for(int i = 0; ; i++)
    {
        if(candies < (i + 1))
        {
            child[i % num_people] += candies;
            break;
        }

        child[i % num_people] += (i + 1);
        candies -= (i + 1);
        printf("%d", child[i % num_people]);
    }

    *returnSize = num_people;

    return child;
}
