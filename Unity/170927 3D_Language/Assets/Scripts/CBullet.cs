using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CBullet : CRyuUnit
{

	// Use this for initialization
	void Start ()
    {
	}
	
	// Update is called once per frame
	void Update ()
    {
        this.transform.Translate(Vector3.forward*Time.deltaTime*5);
    }


    private void OnTriggerEnter(Collider tCollier)
    {
        if(true == tCollier.CompareTag("tagEnemy"))
        {
            Destroy(this.gameObject);
            Destroy(tCollier.gameObject);
        }
    }

}
