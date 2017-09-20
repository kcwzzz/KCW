using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CAlberto : MonoBehaviour {

    public Animator mpAnimator = null;

	// Use this for initialization
	void Start () {

        mpAnimator =  GetComponentInChildren<Animator>();
        
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void DoAttack()
    {
        mpAnimator.SetTrigger("mTrigAttack");
    }

}
