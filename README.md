## OOCatcher

* Used Memento design pattern for saving each move

* Line segment (line5) and point are from OOADANCES 

* Overall the human is constructed according to the torso_starting point and canvas size with fixed proportions

The program estimates whether the object is reachable by human or 
not in the current position,  and if it is not,  it calls walk(int step); 
and then for grabing I estimate the angle between object's center 
and _torso's end point, which helps to rotate the torso and remaining parts to reach the object. 

If the algorithms succeeds meaning 3 fingers' endpoints are inside the object, then program outputs "Man found the object"

The illustrations are done with OPENCV 4.52, so for testing the program it is required extension. 

I have created executable and attached opencv's dll for release mode. Alos, the illustrations are in result_illustrations folder



