// PP1 Project Grade Report.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <limits>
#include <iterator>
#include <regex>
#include <vector>
using namespace std;

//create a structure to hold students first and last names, as well as the test grades
// the structure will also hold the students average and letter grade based on the average
struct student {
    string First_Name;
    string Last_Name;
    double test1;
    double test2;
    double test3;
    double test4;
    double Final_Test;
    double Average;
    string Letter_Grade;
};

string ChooseAFile()
{
    //input: file name
    //output: file name 

    //default file for testing
    string deffname = "CIT1325.txt";
    
    string fname = "";
    cout << "Enter filename (default CIT1325.txt): " << flush;

    //user inputs filename
    getline(cin, fname);
    // if enter pressed or input empty then use deffname
    if (fname.empty()) {
        fname = deffname;
    }
    else {
        //otherwise use what was entered
    }
    //cout << "DEBG: Got " << fname << endl;
    return fname;
}

void print_allstudents_vector(vector<student> studentlist) {
    // input: studentlist vector (allstudents)
    // ouput: allstudents vector
    // Loop through studentlist and print out each item in student structure
    //   if empty record found break to avoid printing extraneous values

    //create output file for write
    ofstream out_file;
    //stores last name length 
    int lName_length;
    //open output file 
    out_file.open("GradeReport.txt");
    // write report header
    out_file << "First Name\tLast Name\tTest 1\tTest 2\tTest 3\tTest 4\tFinal Test\tGrade Average\tLetter Grade\n";
    out_file << "------------------------------------------------------------------------------------------------------------\n";
    // outputs updated student report with average and letter grade
    for (unsigned int i = 0; i < studentlist.size(); i++) {
        if (studentlist[i].First_Name == "") {
            break;
        }
        //get last name's size
        lName_length = studentlist[i].Last_Name.size();

        //if the last name's Last_Name.size() is greater than 7 the last name gets one tab after the name
        // else the name gets two tabs after the name
        if (lName_length > 7)
        {
            //cout << i << ":";
            // print for testing
            cout << studentlist[i].First_Name << "\t\t";
            cout << studentlist[i].Last_Name << "\t";
            cout << studentlist[i].test1 << "\t";
            cout << studentlist[i].test2 << "\t";
            cout << studentlist[i].test3 << "\t";
            cout << studentlist[i].test4 << "\t";
            cout << studentlist[i].Final_Test << "\t\t";
            cout << studentlist[i].Average << "\t\t";
            cout << studentlist[i].Letter_Grade << endl;

            //output_file << i << ":";
            //print to output to file
            out_file << studentlist[i].First_Name << "\t\t";
            out_file << studentlist[i].Last_Name << "\t";
            out_file << studentlist[i].test1 << "\t";
            out_file << studentlist[i].test2 << "\t";
            out_file << studentlist[i].test3 << "\t";
            out_file << studentlist[i].test4 << "\t";
            out_file << studentlist[i].Final_Test << "\t\t";
            out_file << studentlist[i].Average << "\t\t";
            out_file << studentlist[i].Letter_Grade << "\n";
        }
        else {
            //cout << i << ":";
            // print for testing
            cout << studentlist[i].First_Name << "\t\t";
            cout << studentlist[i].Last_Name << "\t\t";
            cout << studentlist[i].test1 << "\t";
            cout << studentlist[i].test2 << "\t";
            cout << studentlist[i].test3 << "\t";
            cout << studentlist[i].test4 << "\t";
            cout << studentlist[i].Final_Test << "\t\t";
            cout << studentlist[i].Average << "\t\t";
            cout << studentlist[i].Letter_Grade << endl;

            //out_file << i << ":";
            //print to output to file
            out_file << studentlist[i].First_Name << "\t\t";
            out_file << studentlist[i].Last_Name << "\t\t";
            out_file << studentlist[i].test1 << "\t";
            out_file << studentlist[i].test2 << "\t";
            out_file << studentlist[i].test3 << "\t";
            out_file << studentlist[i].test4 << "\t";
            out_file << studentlist[i].Final_Test << "\t\t";
            out_file << studentlist[i].Average << "\t\t";
            out_file << studentlist[i].Letter_Grade << "\n";
        }
    }
    out_file.close();
 }

void testAverages(vector<student> testList)
{   // input: studentlist vector (allstudents)
    // output: test averages
    // Loop through studentlist and add each item to their respective test for a total number of each test
    // if the vector is empty (NULL) do nothing
    // else add each item for each test to get a total number for each test
    // divide that total by the number of students determined by a counter to get each tests average
    // add those test averages together to get the overall averages
    double test1average = 0;
    double test2average = 0;
    double test3average = 0;
    double test4average = 0;
    double finaltestaverage = 0;
    double overallaverage = 0;
    int count = 0;
    for (int k = 0; k < testList.size(); k++) {
        if (testList[k].test1 == NULL)
        {
        }
        else {
            test1average = test1average + (testList[k].test1);
            test2average = test2average + (testList[k].test2);
            test3average = test3average + (testList[k].test3);
            test4average = test4average + (testList[k].test4);
            finaltestaverage = finaltestaverage + (testList[k].Final_Test);
            //cout << "DEBG: " << count <<  " " << test1average << endl;
            count = count + 1;
        }
    }
    test1average = test1average / count;
    test2average = test2average / count;
    test3average = test3average / count;
    test4average = test4average / count;
    finaltestaverage = finaltestaverage / count;
    overallaverage = (test1average + test2average + test3average + test4average + finaltestaverage) / 5;
    ofstream output_file("GradeReport.txt", ios::app);

    //print for testing
    cout << "Test 1 average: " << test1average << endl;
    cout << "Test 2 average: " << test2average << endl;
    cout << "Test 3 average: " << test3average << endl;
    cout << "Test 4 average: " << test4average << endl;
    cout << "Final Test average: " << finaltestaverage << endl;
    cout << "Overall Test average: " << overallaverage << endl;

    //print to output file
    output_file << "------------------------------------------------------------------------------------------------------------\n";
    output_file << "Test 1 average:\t" << test1average << "\n";
    output_file << "Test 2 average:\t" << test2average << "\n";
    output_file << "Test 3 average:\t" << test3average << "\n";
    output_file << "Test 4 average:\t" << test4average << "\n";
    output_file << "Final Test average:\t" << finaltestaverage << "\n";
    output_file << "Overall Test average:\t" << overallaverage << "\n";
    return;
}


double getMax(vector<student> Max)
{
    // search through each test to find the max grade in each test
    // after getting the max of each test find the max grade from all of the tests
    double test1Max = 0;
    double test2Max = 0;
    double test3Max = 0;
    double test4Max = 0;
    double finalTestMax = 0;
    double classMax = 0;
    
    for (int i = 0; i < Max.size(); i++) {
        if (Max[i].test1 == NULL)
        {

        }
        else
        {
            //test1
            if (test1Max < Max[i].test1)
            {
                test1Max = Max[i].test1;
            }
            //test 2
            if (test2Max < Max[i].test2)
            {
                test2Max = Max[i].test2;
            }
            //test 3
            if (test3Max < Max[i].test3)
            {
                test3Max = Max[i].test3;
            }
            //test 4
            if (test4Max < Max[i].test4)
            {
                test4Max = Max[i].test4;
            }
            //final test
            if (finalTestMax < Max[i].Final_Test)
            {
                finalTestMax = Max[i].Final_Test;
            }
        }
    }
    // have all largest test value at this point for all tests
    // now compare all the largest found test grades to see what is largest out of all test grades
    // and output it

    classMax = max({ test1Max, test2Max, test3Max, test4Max, finalTestMax });
    // append the max to the output file
    // and also print for testing
    ofstream out_file("GradeReport.txt", ios::app);
    cout << "Highest Test Grade: " << classMax << endl;
    out_file << "Highest Test Grade:\t" << classMax << "\n";
    out_file.close();
    return classMax;
}

void studentsWithMaxGrade(vector<student> studentWithMax, double maxGrade)
{
    // go through each students test grades to determine if the student has the max test grade
    // if the student has the max grade output their first name and last name as well as append the name to the output file
    cout << "Student(s) with max grade: " << endl;
    ofstream output_file("GradeReport.txt", ios::app);
    output_file << "------------------------------------------------------------------------------------------------------------\n";
    output_file << "Student(s) with max grade:" << "\t" << "\n";
    for (int i = 0; i < studentWithMax.size(); i++)
    {
        if (studentWithMax[i].test1 == NULL)
        {
        }
        else
        {
            if (studentWithMax[i].test1 == maxGrade)
            {
                cout << studentWithMax[i].First_Name << " " << studentWithMax[i].Last_Name << endl;
                output_file << studentWithMax[i].First_Name << "\t" << studentWithMax[i].Last_Name << "\n";
            }
            if (studentWithMax[i].test2 == maxGrade)
            {
                cout << studentWithMax[i].First_Name << " " << studentWithMax[i].Last_Name << endl;
                output_file << studentWithMax[i].First_Name << "\t" << studentWithMax[i].Last_Name << "\n";
            }
            if (studentWithMax[i].test3 == maxGrade)
            {
                cout << studentWithMax[i].First_Name << " " << studentWithMax[i].Last_Name << endl;
                output_file << studentWithMax[i].First_Name << "\t" << studentWithMax[i].Last_Name << "\n";
            }
            if (studentWithMax[i].test4 == maxGrade)
            {
                cout << studentWithMax[i].First_Name << " " << studentWithMax[i].Last_Name << endl;
                output_file << studentWithMax[i].First_Name << "\t" << studentWithMax[i].Last_Name << "\n";
            }
            if (studentWithMax[i].Final_Test == maxGrade)
            {
                cout << studentWithMax[i].First_Name << " " << studentWithMax[i].Last_Name << endl;
                output_file << studentWithMax[i].First_Name << "\t" << studentWithMax[i].Last_Name << "\n";
            }
        }
    }
        output_file.close();
    return;
}
string get_letter_grade(double average) {
    // if the students average is in any of the ranges below output that letter grade
    string grade = "UNDEF";  // set undefined to make sure cases are matched

    if (average >= 90.0 && average <= 100) { grade = "A"; }
    if (average >= 80.0 && average <= 90)  { grade = "B"; }
    if (average >= 70.0 && average <= 80)  { grade = "C"; }
    if (average >= 60.0 && average <= 70)  { grade = "D"; }
    if (average >= 0.0 && average <= 60)   { grade = "F"; }
    return grade;
}
int main()
{   // variable for outputting what was being checked for possible errors
    bool debug = false;

    // chosenfile stores what file was inputted in choose a file
    string chosenFile = ChooseAFile();

    // needed to find where files were being stored 
    //system("dir"); //system("pause");

    //read = 1 line of report read
    string read;

    // open input file filename for read    
    ifstream infile(chosenFile);   
    
    //create a vector to hold student structure data of no more than 30 entries
    vector<student> allstudents(30);
    student currentStudent;

    //test if input file can be opened otherwise err
    if (infile.is_open())
    {
        if (debug == true) { cout << "DEBG: " << chosenFile << " open success." << endl; }
        // Now read each line, format is
        // Firstname LastName Test1 Test2 Test3 Test4 TestFinal
        string input_line;
        int loopcount = 0;  // track where we are in the loop to put into array
        //if the file does not err
        while (infile.good()) {
            // read each line and store into vector student_vector
            // once entire file is read, close file and update student vector
            //getline reads eachrow and stores that into input_line which is then stored into read
            getline(infile, input_line);
            read = input_line;
            smatch regex_matches;
            string word;
            stringstream ray(read);
            if (debug == true) { cout << "DGB: InputLine = " << read << endl; }

            // regex function that gets the individual variables of the string read, if they match (First Name, Last Name, Test1, Test2, Test3, Test4, Final Test)
            //The pattern in parenthesis is stored in regex_matches
            // The ^ is the start of the matching
            // The ([a-zA-Z]) means that the first part of the line has to be a word with either upper or lower case letters
            // The \\s+ designates all white space 
            // The ([0-9.]+) gets any number containing the numbers 0-9 at any size, and the . matches if there is a decimal or there is not decimal 
            // The .*$ means to match everything from the start to the end
            regex regex_pattern("^([a-zA-Z]+)\\s+([a-zA-Z]+)\\s+([0-9.]+)\\s+([0-9.]+)\\s+([0-9.]+)\\s+([0-9.]+)\\s+([0-9.]+).*$");
            regex_match(read, regex_matches, regex_pattern);

       

            //put items above into allstudents vector using loopcount as the index in the vector
            //order 1=First_Name 2= Last_Name 3=test1 4=test2 5=test3 6=test4 and 7=Final_Test
            // also convert strings to doubles while here
            allstudents[loopcount].First_Name   = regex_matches[1];
            allstudents[loopcount].Last_Name    = regex_matches[2];
            allstudents[loopcount].test1        = stod(regex_matches[3]);
            allstudents[loopcount].test2        = stod(regex_matches[4]);
            allstudents[loopcount].test3        = stod(regex_matches[5]);
            allstudents[loopcount].test4        = stod(regex_matches[6]);
            allstudents[loopcount].Final_Test   = stod(regex_matches[7]);
            
            // get the student average sum of all grades, final grade x2 / 5
            double average_grade = 0;
            average_grade = (allstudents[loopcount].test1 + allstudents[loopcount].test2 + allstudents[loopcount].test3 + allstudents[loopcount].test4 + (allstudents[loopcount].Final_Test * 2)) / 6.0;
            allstudents[loopcount].Average = average_grade;

            //calculate lettergrade which is based on average_grade
            string letter_grade = "";
            letter_grade = get_letter_grade(average_grade);
            allstudents[loopcount].Letter_Grade = letter_grade;

            //debug to see what input line is 
            if (debug == true) { cout << "DEBG: " << input_line << endl; }
            loopcount = loopcount + 1;
            //cout << endl;
        }
    }
    else {
        cout << "Error: " << chosenFile << " open failure." << endl;
    }
    
    // at this point, data file has been read and stored per project requirement
    // Now adding the end of report information

    //ouput allstudents vector
    print_allstudents_vector(allstudents);

    //calculate all tests averages and the average of those averages and append them to the file
    testAverages(allstudents);

    //output Max from all tests
    // return max value
    double max_grade;
    max_grade = getMax(allstudents);
    
    //pass max grade to function to find students with max grade
    studentsWithMaxGrade(allstudents, max_grade);

    // always close opened files
    infile.close();
    
    return 0;

}