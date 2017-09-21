using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CSlime : CUnit {

	// Use this for initialization
	void Start () {

        CreateAni();

    }
	
	// Update is called once per frame
	void Update () {

        this.transform.position = Vector3.MoveTowards(this.transform.position, 
            Vector3.zero,  0.2f * Time.deltaTime);
        //이전 업데이트에서 현재 업데이트까지 걸린시간 1/60;


	}
}
