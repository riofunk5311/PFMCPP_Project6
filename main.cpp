/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr.
 there is only one reason for `compare` to return nullptr.
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {} //1
    int value;//2
    std::string name; //3
};

struct Comparison //4
{
    T* compare( T& a, T& b ) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float GPA { 2.5f }, SAT { 3.5f };
    float updateScore(float updatedGPA)      //12
    {
        std::cout << "U's GPA value: " << GPA << std::endl;
        GPA = updatedGPA;
        std::cout << "U's GPA updated value: " << GPA << std::endl;
        while( std::abs(SAT - GPA) > 0.1f )
        {
            SAT += 0.5f;
        }
        std::cout << "U's SAT updated value: " << SAT << std::endl;
        return SAT * GPA;
    }
};

struct UpdateGPA
{
    static float updateScore( U& that, float& updatedGPA )        //10
    {
        std::cout << "U's GPA value: " << that.GPA << std::endl;
        that.GPA = updatedGPA;
        std::cout << "U's GPA updated value: " << that.GPA << std::endl;
        
        while( std::abs(that.SAT - that.GPA) > 0.1f )
        {
            that.SAT += 0.5f;
        }
        std::cout << "U's SAT updated value: " << that.SAT << std::endl;
        return that.SAT * that.GPA;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1( 5, "name" );                                             //6
    T t2( 5, "name2" );                                            //6
    
    Comparison f;                                                  //7
    auto smaller = f.compare( t1, t2 );                         //8
    
    if ( smaller != nullptr )
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }//9
    else
    {
        std::cout << "when both value of a and b are equal" << std::endl;
    }
    
    U u;
    float updatedValue = 5.f;
    std::cout << "[static func] u's multiplied values: " << UpdateGPA::updateScore( u, updatedValue ) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updateScore( updatedValue ) << std::endl;
}
