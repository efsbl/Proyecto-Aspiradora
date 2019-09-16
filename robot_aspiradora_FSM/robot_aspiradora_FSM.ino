

enum STATE {
  OFF, 
  MOVING, 
  LOOKING_LEFT, 
  LOOKING_RIGHT,
  TURNING_LEFT,
  TURNING_RIGHT,
  NEED_TO_AVOID,
  AVOIDING,
  TURNING_AROUND};
  
enum STATE current_state, last_state;

boolean distance_done, obstacle_done, obstacle, servo_done, ok_to_go, motor_done;
String mode = "none";
int choose;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
 //Tarea automática que ejecuta la lógica de cambios de estados de la máquina de estados
 
 switch (current_state) {
  
  case OFF:
    if ( mode == "automatic"){
      last_state=current_state;
      current_state=MOVING;
    }
    break;
   
  case MOVING:
   
    if ((obstacle)&&(last_state=TURNING_AROUND)) {
      last_state=current_state;
      current_state=OFF;
    }else{
      last_state=current_state;
      distance_done= false;
      obstacle_done= false;
      current_state=NEED_TO_AVOID;   
    }
    break;
    
  case NEED_TO_AVOID:
    if (obstacle_done) {
      obstacle_done= false;
      distance_done= false;
      if (obstacle){
        current_state=AVOIDING;
      }else{
        current_state=MOVING;
      }
    }
    break;
    
  case AVOIDING:
    last_state=current_state;
    choose= random(0,1);
    if(choose==1){
      current_state=LOOKING_RIGHT;
    }else{
      current_state=LOOKING_LEFT;  
    }
    break;

  case LOOKING_RIGHT:
    if(servo_done){
      servo_done=false;
      if(ok_to_go){
        last_state=current_state;
        current_state=TURNING_RIGHT;  
      }else if (last_state!=LOOKING_LEFT){
        last_state=current_state;
        current_state=LOOKING_LEFT;  
      }else{
        last_state=current_state;
        current_state=TURNING_AROUND;  
      }
    }
    break;

  case LOOKING_LEFT:
    if(servo_done){
      servo_done=false;
      if(ok_to_go){
        last_state=current_state;
        current_state=TURNING_LEFT;  
      }else if (last_state!=LOOKING_RIGHT){
        last_state=current_state;
        current_state=LOOKING_RIGHT;  
      }else{
        last_state=current_state;
        current_state=TURNING_AROUND;  
      }
    }
    break;

   case TURNING_AROUND:
    if(motor_done){
      motor_done=false;
      last_state=current_state;
      current_state=MOVING;
      }
   break;

   case TURNING_RIGHT:
   if(motor_done){
      motor_done=false;
      last_state=current_state;
      current_state=MOVING;
      }
   break;

   case TURNING_LEFT:
   if(motor_done){
      motor_done=false;
      last_state=current_state;
      current_state=MOVING;
      }
   break;
   
  default:
    break;
  }

}
