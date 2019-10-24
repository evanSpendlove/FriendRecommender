for(i=0;i<=total_users;i++) /* Looping through all users as we standardise their username capitalisation */
    {
        for(j=0;j<100 && user_List[i].username[j] != '\n';j++) /* Looping through all characters in each username */
        {
            if(j == 0) /* For the first character of each username...*/
            {
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z') /* If it is a lowercase letter */
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32; /* Make it uppercase */
                }
            }
            else if (user_List[i].username[j] == ' ') /* If the character is a space */
            {
                ++j; /* If this character is a space, capitalise the next letter */
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z')
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32;
                }
            }
            else
            {
                if(user_List[i].username[j] >= 'A' && user_List[i].username[j] <= 'Z') /* If it is a capital letter, make it lowercase */
                {
                    user_List[i].username[j] = user_List[i].username[j] + 32;
                }
            }
        }
    }