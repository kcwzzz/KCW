using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CSlime : CEnemy {

	// Use this for initialization
	void Start ()
    {
        StartAIRyu();
    }
	
	// Update is called once per frame
	void Update () {

        //DoMove();
        
        Vector3 tPosition = new Vector3(this.transform.position.x,
            this.transform.position.y + 0.5f, this.transform.position.z);

        Vector3 tDir = this.transform.forward;
        Debug.DrawRay(tPosition, tDir * 10.0f, Color.red);
        
        
	}
}
