/* RE-WRITE: NEED A BOOLEAN TO TRIP IF MATCH FOUND THEN CHECK BOOL AFTER LOOP */

int friendMatch = 0;

for(i=0;i<total_users && suggestion_count != 2; i++) /* Loops through the users to find suggestions who meeet criteria below*/
    {
        if(i != user_index) /* If the user in user_List is not the user selected... */
        {
            for(j=0;j<user_List[user_index].friend_count;j++) /* Loops through the friends of the user_selected */
            {
                if(strcmp(user_List[i].username, user_List[user_index].friend[j]) == 0) /* Checks if the suggestion is already a friend of the user selected */
                {
                    friendMatch = 1;
                }
                if(strcmp(user_List[i].username, friend_suggest[j]) == 0) /* Checks if the suggestion is already a friend suggestion */
                {
                    friendMatch = 1;
                }
            }

            if(friendMatch != 1)
            {
                strcpy(friend_suggest[suggestion_count], user_List[i].username); /* Copies the username of the selected user to the friend_suggest array */
                suggestion_count++; /* Increments count of suggestions found */
            }
        }
        friendMatch = 0;
    }