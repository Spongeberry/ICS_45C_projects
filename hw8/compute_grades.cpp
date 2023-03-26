#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

void error(string msg)
{
    cout << "Error: " << msg << endl;
}

class Student{
    static constexpr double quiz_weight = 0.4;
    static constexpr double hw_weight = 0.3;
    static constexpr double final_weight = 0.3;
public:
    string first_name;
    string last_name;
    vector<int> quiz;
    vector<int> hw;
    double quiz_ave;
    double hw_ave;
    double final_score;
    int course_score;
    string course_grade;

public:

    void compute_grade(){
        if (quiz.size() == 0) {
            quiz_ave = 0;
        } else if (quiz.size() == 1) {
            quiz_ave = quiz[0];
        } else {
            auto min_score = min_element(quiz.begin(), quiz.end());
            quiz_ave = (accumulate(quiz.begin(), quiz.end(), 0.0) - *min_score) / (quiz.size() - 1);
        }
        
        if (hw.size() == 0) {
            hw_ave = 0;
        } else {
            hw_ave = accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
        }
        
        course_score = round(quiz_weight * quiz_ave + hw_weight * hw_ave + final_weight * final_score);
        
        if (course_score >= 97) {
            course_grade = "A+";
        } else if (course_score >= 93) {
            course_grade = "A";
        } else if (course_score >= 90) {
            course_grade = "A-";
        } else if (course_score >= 87) {
            course_grade = "B+";
        } else if (course_score >= 83) {
            course_grade = "B";
        } else if (course_score >= 80) {
            course_grade = "B-";
        } else if (course_score >= 77) {
            course_grade = "C+";
        } else if (course_score >= 73) {
            course_grade = "C";
        } else if (course_score >= 70) {
            course_grade = "C-";
        } else if (course_score >= 67) {
            course_grade = "D+";
        } else if (course_score >= 63) {
            course_grade = "D";
        } else if (course_score >= 60) {
            course_grade = "D-";
        } else {
            course_grade = "F";
        }
    }
    

    void read([[maybe_unused]]istream & in){}

    void print(ostream & out) const{
        out << "Name\t" << first_name << " " << last_name << endl;
        out << "HW Ave:\t" << hw_ave << endl;
        out << "QZ Ave:\t" << quiz_ave << endl;
        out << "Final:\t" << final_score << endl;
        out << "Total:\t" << course_score << endl;
        out << "Grade:\t" << course_grade << endl << endl;
    }

    friend ostream & operator << (ostream & out, const Student & student){
        student.print(out);
        return out;
    }

    friend istream & operator >> (istream & in, Student & student){
        student.read(in);
        return in;
    }
};


class Gradebook{
    vector<Student> students;

public:
    
    void compute_grades(){
        for (auto & student : students){
            student.compute_grade();
        }
    }


    void sort(){
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.last_name == b.last_name) {
                return a.first_name < b.first_name;
            }
            return a.last_name < b.last_name;
            }
        );
    }


    void print(ostream & out) const{
        for (auto student : students){
            out << student;
        }
    }


    void read(istream & in){
        string line;
        Student student;
        while (getline(in, line)) {
            if (line.empty()) {
                // If we encounter an empty line, it marks the end of a student record
                // Construct a Student object and add it to our list of students
                stringstream ss(line); // initialize ss with line
                ss >> student; // read the student record from the stringstream
                students.push_back(student);
                student.first_name = "Missing";
                student.last_name = "Name";
                student.quiz.clear();
                student.hw.clear();
                student.quiz_ave = 0.0;
                student.hw_ave = 0.0;
                student.final_score = 0.0;
                student.course_score = 0.0;
                student.course_grade = "F";
            } else {
                // If the line is not empty, it contains data for the current student record
                // We ignore any lines that do not match one of the expected keywords
                stringstream ss(line); // initialize ss with line
                string keyword;
                ss >> keyword;
                if (keyword == "Name") {
                    string first_name, last_name;
                    ss >> first_name >> last_name;
                    student.first_name = first_name;
                    student.last_name = last_name;
                } else if (keyword == "Quiz") {
                    double score;
                    while (ss >> score) {
                        if (score > 100 || score < 0){
                            error("invalid percentage " + to_string(score));
                        }
                        student.quiz.push_back(score);
                    }
                } else if (keyword == "HW") {
                    double score;
                    while (ss >> score) {
                        if (score > 100 || score < 0){
                            error("invalid percentage " + to_string(score));
                        }
                        student.hw.push_back(score);
                    }
                } else if (keyword == "Final") {
                    double score;
                    if (score > 100 || score < 0){
                            error("invalid percentage " + to_string(score));
                        }
                    ss >> score;
                    student.final_score = score;
                }
            }
        }
    }


    friend ostream & operator << (ostream & out, const Gradebook & gb){
        gb.print(out);
        return out;
    }

    friend istream & operator >> (istream & in, Gradebook & gb){
        gb.read(in);
        return in;
    }
};


int main(){
    ifstream in("gradebook.txt");
    Gradebook gb;
    in >> gb;
    gb.sort();
    gb.compute_grades();
    ofstream out("course_grades.txt");
    out << gb;
}