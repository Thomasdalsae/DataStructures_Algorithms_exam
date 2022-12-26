
* FixedUpdate = Multiple times per frame.
* Update()  = Once per Frame
* Animation update = Multiple times per frame.
* LateUpdate = once per frame aswell but after Animation Update.
* GUI Update = Multiple time per frame.



When working with AI we will mainly use FIxedUpdate,Update and LateUpdate.
* When working with Speed and rotation always use Time.deltaTime.