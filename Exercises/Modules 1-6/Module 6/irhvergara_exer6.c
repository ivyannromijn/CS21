//VERGARA, Romijn
// CMSC 21 ST2L - Exercise 6


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//given structures in the exercise
typedef struct song_tag {                                
    char title[20], artist[20], album[20];
    struct song_tag *nextSong;
} song;

typedef struct playlist_tag {
    char name[50];
    int songCount;
    song *songHead;
    struct playlist_tag *next;
} playlist;

//----------------------------------------------------------------------//
//PRINT FUNCTIONS
void printAvailablePlaylist(playlist *head) {
    printf("THE PLAYLISTS AVAILABLE ARE:\n");
    int i = 1;                                                              //initiallized to 1 so the first row will be printed as [1]

    while (head != NULL)                                                    //Error prompt if there is no playlist available
    {
        printf("    [%d] %s\n", i, head->name);                             //prints the name of the playlist and its number
        head = head->next;                                                  //moves the head to another
        i++;                                                                //increment the playlist number
    }
}
void printAvailableSongs(song *head){ 
    printf("\nTHE SONGS AVAILABLE ARE:\n");
    int i = 1;                                                              //initiallized to 1 so the first row will be printed as [1]


    while(head != NULL)                                                     //Error prompt if there is no song available
    { 
        printf("    [%d] %s by %s\n", i, head->title, head->artist);        //prints the name of the song and its number
        head = head->nextSong;                                              //moves the head to another structure member
        i++;
    }
}

///----------------------------------------------------------------------//
void addPlaylist(playlist **head) {

    playlist *new = (playlist *) malloc (sizeof(playlist));

    printf("Enter playlist name: ");
    scanf(" %[^\n]s", new->name);                                                           //inputs the new entered playlist to the name structure

    if ((*head) == NULL || ((*head) != NULL && strcmp((*head)->name, new->name) > 0)) {     // if head is vacant, or if head is occupied and head playlist 
                                                                                            // is less than the added playlist, then insert playlist or change head 
        new->next = (*head);                                                                
        (*head) = new;
    }
    
    else {                                                                                  // else, add to the middle or tail
        playlist *temp = (*head);

        while (temp->next != NULL && strcmp(temp->next->name, new->name) <= 0)              // sorts the playlist alphabetically
        {               
            temp = temp->next;
        }

        if (strcmp(temp->name, new->name) == 0) {                                            // error prompt to avoid duplicate of playlist name
            printf("\nPlaylist name already exists!\n");
            return;
        }

        new->next = temp->next;                                           
        temp->next = new;                                                                   //holds the last node
    }
    printf("\nSuccessfully added playlist!\n");
} 

//----------------------------------------------------------------------//
void addSong (playlist **head) {

    char selectedPlaylist[20];                                                               // initialize character var                                         

    if ((*head) == NULL) {                                                                  // error prompt if there's no existing playlist 
        printf("There are no playlists yet!\n");
        return;
    }
    
    printAvailablePlaylist(*head);                                                          //prints all playlist

    printf("\nEnter playlist name: ");
    scanf(" %[^\n]s", selectedPlaylist);

    playlist *temp1 = *head;

    while ((temp1) != NULL) {                                                               // check if the playlist is existing
        if (strcmp(selectedPlaylist, temp1->name) == 0) 
        {
            break;
        }
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {                                     
        printf("Invalid playlist!\n");
        return;
    } 

    song *new = (song *) malloc (sizeof(song));                                             //allocates new memory for a structure pointer

    printf("\nEnter song title: ");
    scanf(" %[^\n]s", new->title);
    printf("Enter song artist: ");
    scanf(" %[^\n]s", new->artist);
    printf("Enter song album: ");
    scanf(" %[^\n]s", new->album);

    if (temp1->songHead == NULL || (temp1->songHead != NULL && strcmp(temp1->songHead->title, new->title) > 0)){
        new->nextSong = temp1->songHead;                                    // if songHead is vacant, or if songHead is occupied and songHead 
        temp1->songHead = new;                                              // is less than the added song, then insert song or change songHead
    }
    
    else {                                                                  // else, add to the middle or tail
        song *temp2 = temp1->songHead;

        while (temp2->nextSong != NULL && strcmp(temp2->nextSong->title, new->title) <= 0) {     // sort the songs alphabetically
            temp2 = temp2->nextSong;
        }

        new->nextSong = temp2->nextSong;
        temp2->nextSong = new;
    }

    printf("\nSuccessfully added song to playlist!\n");
    temp1->songCount++;                                                     // update the number of songs in the playlist 
}

//----------------------------------------------------------------------//
void removeSong (playlist **head) {

    char selectedPlaylist[20];                                             // initialize character var

    if ((*head) == NULL) {                                                  // check if there is an existing playlist
        printf("There are no playlists yet!\n");
        return;
    }
    
    printAvailablePlaylist(*head);                                          //prints avail playllist 

    printf("\nEnter playlist name: ");
    scanf(" %[^\n]s", selectedPlaylist);

    playlist *temp1 = *head;

    while((temp1) != NULL) {                                                // check if the playlist is existing
        if(strcmp(selectedPlaylist, temp1->name) == 0) 
        {
            break;
        }
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {
        printf("Invalid playlist!\n");
        return;
    } 

    char deleteTitle[20], deleteArtist[20];                                //initialize char var
    song *delete = temp1->songHead;

    if (delete == NULL) {                                                 //  check if there is a song in the selected playlist
        printf("\nThere are no songs in this playlist!\n");
        return;
    }

    printAvailableSongs(temp1->songHead);

    printf("\nEnter song title to delete: ");
    scanf(" %[^\n]s", deleteTitle);
    printf("Enter song artist to delete: ");
    scanf(" %[^\n]s", deleteArtist);

    while (delete != NULL) {                                              
        if ((strcmp(delete->title, deleteTitle) == 0) && (strcmp(delete->artist, deleteArtist) == 0)) // check if song is existing
        {       
            break;
        }
        delete = delete->nextSong;
    }
    
    if (delete == NULL) {        
        printf("\nSong not found!\n");
        return;
    }

    if (delete == temp1->songHead) {                                        // removes the selected song
        temp1->songHead = temp1->songHead->nextSong;    
        free(delete);
    } 
    else { 
        song *temp2 = temp1->songHead;

        while(temp2->nextSong != delete) {
            temp2 = temp2->nextSong;
        }

        temp2->nextSong = delete->nextSong;
        free(delete);
    } 
    printf("\nSuccessfully deleted song!\n");
    temp1->songCount--;                                                   // update the number of songs in the playlist   
}

//----------------------------------------------------------------------//
void viewPlaylist (playlist **head) {

    char selectedPlaylist[20];                                           // initialize character var

    if ((*head) == NULL) {                                               // check if there is an existing playlist
        printf("\nThere are no playlists yet!\n");
        return;
    }

    printAvailablePlaylist(*head);

    printf("\nEnter playlist name: "); 
	scanf(" %[^\n]s", selectedPlaylist);

    playlist *temp = *head;

    while(temp != NULL) {                                               // check if the playlist is existing
        if (strcmp(selectedPlaylist, temp->name) == 0){
            break;
        }
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("\nInvalid playlist!\n");
        return;
    } 
    printf("\n");
    printf("PLAYLIST: %s\n", temp->name);                              // print the selected playlist and corresponding songs
    printf("SONG COUNT: %d\n", temp->songCount);
    
    for(song *i = temp->songHead; i !=NULL; i = i->nextSong) {
        printf("\tSONG TITLE: %s\n", i->title);
        printf("\tSONG ARTIST: %s\n", i->artist);
        printf("\tSONG ALBUM: %s\n\n", i->album);
    }
}

///----------------------------------------------------------------------//
void viewAllData(playlist *head) {

    if (head == NULL) {                                              // check if there is an existing playlist
        printf("There are no playlists yet!\n");
        return;
    }
    
    while(head != NULL) {                                           // print all the playlists and corresponding songs if any
        printf("PLAYLIST: %s\n", head->name);
        printf("SONG COUNT: %d\n", head->songCount);

        song *temp = head->songHead;
        while(temp != NULL) {
            printf("\tSONG TITLE: %s\n", temp->title);
            printf("\tSONG ARTIST: %s\n", temp->artist);
            printf("\tSONG ALBUM: %s\n\n", temp->album);
            
            temp = temp->nextSong; 
        }
        head = head->next;
    }
}

//----------------------------------------------------------------------//
void saveData(playlist *head) {

    FILE *fp = fopen("Playlists.txt", "w");    
    
    if (head == NULL) {
        printf("There are no data to be saved.\n");
        return;
    }
    
    playlist *temp = head;
    
    int playlistCount = 0;
    while (temp != NULL) {
        playlistCount++;
        temp = temp->next;
    }

    fprintf(fp, "%d\n", playlistCount);
     /* saves the information added to the file */
    while (head != NULL) {   
        fprintf(fp, "%s\n", head->name);
        fprintf(fp, "%d\n", head->songCount);

        song *temp = head->songHead;
        while (temp != NULL) {
            fprintf(fp, "%s\n", temp->title);
            fprintf(fp, "%s\n", temp->artist);
            fprintf(fp, "%s\n", temp->album);

            temp = temp->nextSong;
        }
        head = head->next;
    }
    printf("Successfully saved data.\n");
    fclose(fp); //IMPORTANT: this makes sure that the file is closed so that no data will be changed unknowingly
}

//----------------------------------------------------------------------//
void loadData(playlist **head) {
    
    FILE *fp = fopen("Playlists.txt", "r");
 
    if (fp == NULL) {
        printf("File was not opened!\n\n");
        printf("Computer created a file for you....\n\n");
        return;
    }

    int playlistCount;
    fscanf(fp, "%d\n", &playlistCount);

    if (playlistCount <= 0) {
        printf("There are no data to be loaded.");
        return;
    }

    for (int i = 0; i < playlistCount; i++) {
        playlist *new = (playlist *) malloc (sizeof(playlist));

        fscanf(fp, " %[^\n]s", new->name);
        fscanf(fp, "%d\n", &new->songCount);

        if (new->songCount > 0) {
            for (int j = 0; j < new->songCount; j++) {
                song *newSong = (song *) malloc (sizeof(song));

                fscanf(fp, " %[^\n]s", newSong->title);
                fscanf(fp, " %[^\n]s", newSong->artist);
                fscanf(fp, " %[^\n]s", newSong->album);

                if (new->songHead == NULL) {
                    newSong->nextSong = new->songHead;
                    new->songHead = newSong;
                } 
                
                else {                                              // insert at middle and tail
                    song *temp = new->songHead;
                    
                    while (temp->nextSong != NULL) {
                        temp = temp->nextSong;
                    }
                    newSong->nextSong = temp->nextSong;
                    temp->nextSong = newSong;
                }
            }
        }
                                                                   // insert to head 
        if ((*head) == NULL) {
            new->next = (*head);
            (*head) = new;
        } 
        
        else {
            playlist *temp1 = (*head);
            while (temp1->next != NULL) {
                temp1 = temp1->next;
            }
            new->next = temp1->next;
            temp1->next = new;
        }
    }
    printf("Successfully loaded data.\n"); 
    fclose(fp); //IMPORTANT: this makes sure that the file is closed so that no data will be changed unknowingly
}

//----------------------------------------------------------------------//
void FREE(playlist **head) {                                                //de-allocates all memory of dynamic variables
    
    while((*head) != NULL) {
		playlist *temp1 = *head;
		(*head) = (*head)->next;
		
        while(temp1->songHead != NULL) {
            song *temp2 = temp1->songHead;
            temp1->songHead = temp1->songHead->nextSong;
            free(temp2);
	    }
        free(temp1);
	}
}

//----------------------------------------------------------------------//
int main() {

    playlist *head = NULL;
    int choice;
    int choice2;
    
    loadData(&head);                                             // load all data from the start

    while(1) {
        printf("===== MENU =====\n");
        printf("[1] Add Playlist\n");
        printf("[2] Add Song to Playlist\n");
        printf("[3] Remove Song from Playlist\n");
        printf("[4] View a Playlist\n");
        printf("[5] View All Data\n");
        printf("[6] Delete All Data \n");
        printf("[7] Exit\n");
        
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        printf("\n");

        if (choice == 1) {
            addPlaylist(&head);
        }
        else if (choice == 2) {
            addSong(&head);
        }
        else if (choice == 3) {
            removeSong(&head);
        }
        else if (choice == 4) {
            viewPlaylist(&head);
        }
        else if (choice == 5) {
            viewAllData(head);
        }
        else if (choice == 6) {
            FREE(&head);                                     //frees all allocated variables and is not saved
            printf("All data was deleted!\n");
        }
        else if (choice == 7) {
            saveData(head);                                 // save all data before exiting
            FREE(&head);                                    // free all dynamically-allocated variables
            break;                                          // terminate program
        }
        else{
            printf("Wrong input!\n");
        }
    printf("-----------------------------\n");          
    }
}