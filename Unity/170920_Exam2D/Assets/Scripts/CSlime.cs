using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CSlime : CEnemy
{

	// Use this for initialization
	void Start () {

    }

    // Update is called once per frame
    void Update ()
    {
        this.transform.position = Vector3.MoveTowards(this.transform.position,
    Vector3.zero, 1.0f * Time.deltaTime);      
        
        //이전 업데이트에서 현재 업데이트까지 걸린시간 1/60;
	}

}