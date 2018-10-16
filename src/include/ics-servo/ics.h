
class IcsServo {
  using ServoID = std::uint8_t;
  using Position = double;

  int set_position(ServoID, Position);
  int set_free(ServoID);

  int set_stretch(ServoID, std::uint8_t stretch);
  int set_speed(ServoID, std::uint8_t speed);
  int set_current_limit(ServoID, std::uint8_t current_limit);
  int set_temperature_limit(ServoID, std::uint8_t tmperature_limit);

  std::uint8_t get_stretch(ServoID id);
  std::uint8_t get_speed(ServoID id);
  std::uint8_t get_current(ServoID id);
  std::uint8_t get_temperature(ServoID id);
  Position get_position(ServoID id);
};
