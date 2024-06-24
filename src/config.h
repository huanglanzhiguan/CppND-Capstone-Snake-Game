#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <limits>

/**
 * The Config class is used to store and retrieve the player's name, scores.
 * It also provides methods to save and load the scores to and from a file.
 */
class Config {
 public:
  Config() : player_name("Player"), snake_speed(1) {}

  void AskForConfig();
  void SaveToFile(const std::string &filename) const;
  [[nodiscard]] int GetHighestScore() const;
  void SetHighestScore(int score);
  void LoadFromFile(const std::string &filename);
  void PrintScores() const;

  std::string player_name;
  std::unordered_map<std::string, int> scores;
  int snake_speed;

 private:
  [[nodiscard]] static std::string EncryptDecrypt(const std::string &data) ;
};


#endif //CONFIG_H
