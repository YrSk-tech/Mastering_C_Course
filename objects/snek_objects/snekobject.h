 typedef enum SnekKind{
  INTEGER,
  }snek_object_kind_t;

 typedef union SnekData{
    int v_int;
 }snek_object_data_t;

 typedef struct SnekObj{
    snek_object_kind_t kind;
    snek_object_data_t data;
 }snek_object_t;
