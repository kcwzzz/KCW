using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CEnemy : CRyuUnit
{
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update ()
    {
        this.DoMove();	
	}

    override public void DoMove() 
    {
        this.transform.position = Vector3.MoveTowards(this.transform.position,mpScene.GetAlberto().transform.position, Time.deltaTime);
        //forward z축의  +방향으로, 1Unit씩 Self = 로컬 좌표계(알베르토의 좌표) 
    }

}
