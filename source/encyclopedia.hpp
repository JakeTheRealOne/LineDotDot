# include <vector>
# include <unordered_map>
using namespace std;


/**
 * @brief Return the map of all characters and their morse translation
 * 
 * @return unordered_map<char, vector<bool>> {character:morse}
 */
unordered_map<char, vector<bool>> buildCTM ();

/**
 * @brief Return the map of all morse character and their english translation
 * 
 * @return unordered_map<vector<bool>, char> {morse:character}
 */
unordered_map<vector<bool>, char> buildMTC ();