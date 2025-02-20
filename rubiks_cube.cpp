#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class rubiks_cube{
private:
    long long int face1 [256][256], face2[256][256], face3[256][256], face4[256][256], face5[256][256], face6[256][256];
public:
    void populate_faces ()
    {
       long long int gradient_array [4], random_number = 0, result = 0;

        for (int i = 0; i < 4; i++) //Fill the gradient array with randomly selected positive integers.
        {
            do{
                random_number = rand();
            }while (random_number < 0);

            gradient_array[i] = random_number % 256;
        }

        random_number = 0;
        result = 0;

        cout << "Populating matrices" << endl;

        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                do{
                    random_number = rand();
                }while (random_number < 0);

                result = random_number % 4;
                face1[i][j] = gradient_array[result];
            }
        }

        cout << "Face 1 populated " << endl;


        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                do{
                    random_number = rand();
                }while (random_number < 0);

                result = random_number % 4;
                face2[i][j] = gradient_array[result];
            }
        }

        cout << "Face 2 populated" << endl;

        random_number = 1;
        result = 0;

        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                do{
                    random_number = rand();
                }while (random_number < 0);

                result = random_number % 4;
                face3[i][j] = gradient_array[result];
            }
        }

        cout << "Face 3 populated" << endl;

        random_number = 0;
        result = 0;

        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                do{
                    random_number = rand();
                }while (random_number < 0);

                result = random_number % 4;
                face4[i][j] = gradient_array[result];
            }
        }

        cout << "Face 4 populated" << endl;

        random_number = 0;
        result = 0;

        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                do{
                    random_number = rand();
                }while (random_number < 0);

                result = random_number % 4;
                face5[i][j] = gradient_array[result];
            }
        }

        cout << "Face 5 populated" << endl;

        random_number = 0;
        result = 0;

        /*
        * Is causing a segmentation fault
        * |
        * |
        * |
         \/
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; i++)
            {
                do{
                    random_number = rand();
                }while (random_number < 0);

                result = random_number % 4;
                face6[i][j] = gradient_array[result];
            }
        }*/

        cout << "Face 6 populates" << endl;
        cout << "\n";
        cout << "Populated matrices" << endl;
    }

    vector<char> interact()
    {
        vector<char> move_list;
        int intermediate_buffer [256], face_choice = 0, column_choice = 0, row_choice = 0, temporaray_number = 0, row_copy[256], column_copy[256];
        char choice, rotation_choice;
        while (1)
        {
            cout << "Select a face: " <<endl;
            cout << "Face 1" << endl;
            cout << "Face 2" << endl;
            cout << "Face 3" << endl;
            cout << "Face 4" << endl;
            cout << "Face 5" << endl;
            cout << "Face 6" << endl;
            cout << "Your choice : " << endl;
            cin >> face_choice;
            if (face_choice == 1)
            {
                /*
                 * Row rotation from face
                 */
                cout << "Do you want to select a row (r) or a column (c)?: ";
                cin >> choice;

                if (choice == 'r')
                {
                    cout << "Which row do you want to rotate?: ";
                    cin >> row_choice;

                    cout << "Which rotation do you want to do?:";
                    cin >> rotation;

                    if (rotation == 'R')
                    {
                        /* Explanation of the below statements:
                         * The below statements rotate the rows in the right direction.
                         */

                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                intermediate_buffer[j] = face1[i][j];
                                move_list.push_back('R');
                            }

                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                row_copy[j] = face6[i][j];//Copies the row to keep an unmodified copy of the matrix.
                                intermediate_buffer[j] = row_copy[j];//Transfers the copy to the row_copy array.
                            }


                        for (int i = row; i < row;)
                            for (int j = 0; j < 256; j++)
                            {
                                temporaray_number = intermediate_buffer[j];
                                face6[i][j] = temporaray_number;
                            }

                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                row_copy[j] = face3[i][j];//Copies a row and keeps it aside.
                                intermediate_buffer[j] = row_copy[j];//Transfers the copy to the row_copy array.
                            }

                        for (int i = row; i < row;)
                            for (int j = 0; j < 256; j++)
                            {
                                temporaray_number = intermediate_buffer[j];
                                face3[i][j] = temporaray_number;
                            }


                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                row_copy[j] = face5[i][j];//Copies the row to keep an unmodified copy of the matrix.
                                intermediate_buffer[j] = row_copy[j];//Transfers the copy to the row_copy array.
                            }

                        for (int i = row; i < row;)
                            for (int j = 0; j < 256; j++)
                            {
                                temporaray_number = intermediate_buffer[j];
                                face5[i][j] = temporaray_number;
                            }
                        }

                    else if (rotation == 'L')
                    {
                        /* Explanation of the below statements:
                        * The below statements rotate the rows in the left direction.
                        */

                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                intermediate_buffer[j] = face1[i][j];
                                move_list.push_back('L');
                            }

                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                row_copy[j] = face5[i][j];//Copies the row to keep an unmodified copy of the matrix.
                                intermediate_buffer[j] = row_copy[j];//Transfers the copy to the row_copy array.
                            }


                        for (int i = row; i < row;)
                            for (int j = 0; j < 256; j++)
                            {
                                temporaray_number = intermediate_buffer[j];
                                face6[i][j] = temporaray_number;
                            }

                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                row_copy[j] = face3[i][j];//Copies a row and keeps it aside.
                                intermediate_buffer[j] = row_copy[j];//Transfers the copy to the row_copy array.
                            }

                        for (int i = row; i < row;)
                            for (int j = 0; j < 256; j++)
                            {
                                temporaray_number = intermediate_buffer[j];
                                face3[i][j] = temporaray_number;
                            }


                        for (int i = row_choice; i < row_choice;)
                            for (int j = 0; j < 256; j++)
                            {
                                row_copy[j] = face5[i][j];//Copies the row to keep an unmodified copy of the matrix.
                                intermediate_buffer[j] = row_copy[j];//Transfers the copy to the row_copy array.
                            }

                        for (int i = row; i < row;)
                            for (int j = 0; j < 256; j++)
                            {
                                temporaray_number = intermediate_buffer[j];
                                face5[i][j] = temporaray_number;
                            }
                        }

                        for (int i = 0; i < 256; i++)
                        {
                            intermediate_buffer[i] = 0;
                            row_copy[i] = 0;
                        }
                }

                else if (choice == 'c')
                {
                    cout << "Which column do you want to rotate?: ";
                    cin >> column_choice;

                    cout << "Which rotation do you want to do?:";
                    cin >> rotation;

                    if (rotation == 'U')
                        {
                            /* Explanation of the below statements:
                            * The below statements rotate the columns in the upwards direction.
                            */

                            for (int i = 0; i < row_choice;)
                                for (int j = column_choice; j < column_choice; j++)
                                {
                                    intermediate_buffer[j] = face1[i][j];
                                    move_list.push_back('U');
                                }

                            for (int i = ; i < row_choice;)
                                for (int j = 0; j < 256; j++)
                                {
                                    column_copy[j] = face2[i][j];//Copies the column to keep an unmodified copy of the matrix.
                                    intermediate_buffer[j] = column_copy[j];//Transfers the copy to the column_copy array.
                                }


                            for (int i = row; i < row;)
                                for (int j = 0; j < 256; j++)
                                {
                                    temporaray_number = intermediate_buffer[j];
                                    face2[i][j] = temporaray_number;
                                }

                            for (int i = row_choice; i < row_choice;)
                                for (int j = 0; j < 256; j++)
                                {
                                    column_copy[j] = face3[i][j];//Copies a column and keeps it aside.
                                    intermediate_buffer[j] = row_copy[j];//Transfers the copy to the column_copy array.
                                }

                            for (int i = row; i < row;)
                                for (int j = 0; j < 256; j++)
                                {
                                    temporaray_number = intermediate_buffer[j];
                                    face3[i][j] = temporaray_number;
                                }


                            for (int i = row_choice; i < row_choice;)
                                for (int j = 0; j < 256; j++)
                                {
                                    column_copy[j] = face5[i][j];//Copies the column to keep an unmodified copy of the matrix.
                                    intermediate_buffer[j] = column_copy[j];//Transfers the copy to the column_copy array.
                                }

                            for (int i = row; i < row;)
                                for (int j = 0; j < 256; j++)
                                {
                                    temporaray_number = intermediate_buffer[j];
                                    face5[i][j] = temporaray_number;
                                }
                        }

                        else if (rotation == 'D')
                        {
                            /* Explanation of the below statements:
                            * The below statements rotate the rows in the down direction.
                            */

                            for (int i = row_choice; i < row_choice;)
                                for (int j = 0; j < 256; j++)
                                {
                                    intermediate_buffer[j] = face1[i][j];
                                    move_list.push_back('D');
                                }

                            for (int i = row_choice; i < row_choice;)
                                for (int j = 0; j < 256; j++)
                                {
                                    column_copy[j] = face4[i][j];//Copies the column to keep an unmodified copy of the matrix.
                                    intermediate_buffer[j] = row_copy[j];//Transfers the copy to the column_copy array.
                                }


                            for (int i = row; i < row;)
                                for (int j = 0; j < 256; j++)
                                {
                                    temporaray_number = intermediate_buffer[j];
                                    face4[i][j] = temporaray_number;
                                }

                            for (int i = row_choice; i < row_choice;)
                                for (int j = 0; j < 256; j++)
                                {
                                    column_copy[j] = face3[i][j];//Copies a column and keeps it aside.
                                    intermediate_buffer[j] = row_copy[j];//Transfers the copy to the column_copy array.
                                }

                            for (int i = row; i < row;)
                                for (int j = 0; j < 256; j++)
                                {
                                    temporaray_number = intermediate_buffer[j];
                                    face3[i][j] = temporaray_number;
                                }


                            for (int i = row_choice; i < row_choice;)
                                for (int j = 0; j < 256; j++)
                                {
                                    column_copy[j] = face2[i][j];//Copies the column to keep an unmodified copy of the matrix.
                                    intermediate_buffer[j] = column_copy[j];//Transfers the copy to the column_copy array.
                                }

                            for (int i = row; i < row;)
                                for (int j = 0; j < 256; j++)
                                {
                                    temporaray_number = intermediate_buffer[j];
                                    face2[i][j] = temporaray_number;
                                }
                        }
                    }
                }
                else if (choice == 'c')
                {

                }
            }
        }
        return move_list;
    }

    void display()
    {
        cout << "Face 1 : " << endl;
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
                cout << face1[i][j] << "\t";
            cout << "\n";
        }

        cout << "Face 2 : " << endl;
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
                cout << face2[i][j] << "\t";
            cout << "\n";
        }

        cout << "Face 3 : " << endl;
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
                cout << face3[i][j] << "\t";
            cout << "\n";
        }

        cout << "Face 4 : " << endl;
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
                cout << face4[i][j] << "\t";
            cout << "\n";
        }

        cout << "Face 5 : " << endl;
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
                cout << face5[i][j] << "\t";
            cout << "\n";
        }

        cout << "Face 6 : " << endl;
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
                cout << face6[i][j] << "\t";
            cout << "\n";
        }
    }

    void clear_faces()
    {

        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                face1[i][j] = 0;

        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                face2[i][j] = 0;

        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                face3[i][j] = 0;

        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                face4[i][j] = 0;

        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                face5[i][j] = 0;

        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                face6[i][j] = 0;

        cout << "Matrices cleared" << endl;
    }
};


class group_theory
{
protected:
    vector <int> enumerated_list;
public:
    void enumerate_list(vector <char> move_list)
    {
        /*
         * The mapping of moves to numbers is as follows:
         * L (Left) - 0
         * R (Right) - 1
         * U (Up) - 2
         * D (Down) - 3
         */
        for (int i = 0; i < move_list.size(); i++)
        {
            switch(move_list.at(i))
            {
                case 'L' : enumerated_list.push_back(0);
                    break;
                case 'R' : enumerated_list.push_back(1);
                    break;
                case 'U' : enumerated_list.push_back(2);
                    break;
                case 'D' : enumerated_list.push_back(3);
                    break;
                default : break;
            }
        }
    }

    bool is_additive_group()
    {
        bool verifications_array [2]; //Format : {identity element, existence of inverses}

        for (int i = 0; i < enumerated_list.size(); i++)
        {
            if (enumerated_list.at(i) == 0)
                verifications_array[0] = true;
        }

        int current_number = 0, previous_number = 0, inverse_count = 0;

        for (int i = 0; i < enumerated_list.size(); i++)
        {
            if (i-- < 0)
                continue;
            else
            {
                current_number = enumerated_list[i];
                previous_number = enumerated_list[i--];

                if ((current_number - previous_number) == (previous_number - current_number))
                    inverse_count ++;
            }
        }

        if (inverse_count == enumerated_list.size() - 1)
            verifications_array[1] = true;
        if (verifications_array [0] == true && verifications_array [1] == true)
        {
            cout << "The set is an additive group" << endl; //Addition is commutative by itself.
            return true;
        }
        else
        {
            cout << "The set is not an additive group" << endl;
            return false;
        }
    }

    bool is_multiplicative_group ()
    {
        bool verifications_array [2]; //Format : {identity element, existence of inverses}

        for (int i = 0; i < enumerated_list.size(); i++)
        {
            if (enumerated_list.at(i) == 1)
                verifications_array [0] = true;
        }

        int current_number = 0, previous_number = 0, inverse_count = 0;

        for (int i = 0; i < enumerated_list.size(); i++)
        {
            if (i-- < 0)
                continue;
            else
            {
                current_number = enumerated_list.at(i);
                previous_number = enumerated_list.at(i--);

                if ((current_number/previous_number) == (previous_number/current_number))
                    inverse_count++;
            }
        }

        if (inverse_count == enumerated_list.size() - 1)
            verifications_array [1] = true;
        if (verifications_array [0] == true && verifications_array [1] == true)
        {
            cout << "The set is a multiplicative group" << endl;//Multiplication is commutative by itself
            return true;
        }
        else
        {
            cout << "The set is not a multiplicative group" << endl;
            return false;
        }
    }
};

int main()
{
    rubiks_cube rc;
    rc.populate_faces();
    rc.display();
    rc.clear_faces();

    vector <char> move_list;

}
