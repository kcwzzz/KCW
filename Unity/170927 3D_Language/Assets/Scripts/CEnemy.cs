using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CEnemy : CRyuUnit
{
    protected CAlberto mpAlberto = null;

    public void SetAlberto(CAlberto tpAlberto)
    {
        mpAlberto = tpAlberto;
    }

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    override public void DoMove()
    {
        this.transform.position = Vector3.MoveTowards(this.transform.position, mpScene.GetAlberto().transform.position, Time.deltaTime);
        //forward z축의  +방향으로, 1Unit씩 Self = 로컬 좌표계(알베르토의 좌표) 
    }

    public void StartAIRyu()
    {
        StartCoroutine(UpdataAIRyu());
    }

    IEnumerator UpdataAIRyu()
    {
        for (; ; )
        {
            //레이캐스트가 히트가 되면 그쪽으로 이동
            //Debug.Log("UpdataRyu");

            base.DoRatote();

            Vector3 tPosition = new Vector3(this.transform.position.x,
                this.transform.position.y + 0.5f, this.transform.position.z);

            Vector3 tDir = this.transform.forward;

            RaycastHit tRaycastHit;

            if (true == Physics.Raycast(tPosition, tDir, out tRaycastHit, 10.0f))
            {
                if (true == tRaycastHit.collider.CompareTag("tagActor"))
                {
                    float tDistance = tRaycastHit.distance;
                    this.transform.position = Vector3.MoveTowards(this.transform.position, tRaycastHit.collider.transform.position, 1.0f);
                }
            }
            else
            {
                //Debug.Log("no Hit");
            }


            yield return new WaitForSeconds(1.0f);
            //yield waitforseconds 코루틴
            //끝나지 않았지만 리턴
            //코루틴 : 싱글스레드인데 멀티 스레드처럼 보이게 만든 것
        }
    }

    public void StartAIRound()
    {
        StartCoroutine(UpdataAIRound());
    }


    IEnumerator UpdataAIRound()
    {
        for (; ; )
        {
            //레이캐스트가 히트가 되면 그쪽으로 이동
            //Debug.Log("UpdataRyu");

            float tSearchArea = 7.0f;


            Vector3 tPosition = new Vector3(this.transform.position.x,
                this.transform.position.y + 0.5f, this.transform.position.z);
            Vector3 tDir = this.transform.forward;

            Vector3 tAlbertoPosition = new Vector3(mpAlberto.transform.position.x,
                mpAlberto.transform.position.y + 0.5f, mpAlberto.transform.position.z);

            Vector3 tVecDistance = tPosition - tAlbertoPosition;
            float tDistajnce = Mathf.Sqrt(tVecDistance.x * tVecDistance.x + tVecDistance.y * tVecDistance.y + tVecDistance.z * tVecDistance.z);

            if (tDistajnce < tSearchArea)
            {
                Debug.Log("Find Circle");

                //this.transform.localRotation 
                /*
                Quaternion tQ = Quaternion.identity;
                float tAngle = 0.0f;
                Vector3 tAxis = Vector3.zero;

                tQ.ToAngleAxis(out tAngle, out tAxis);
                Quaternion.AngleAxis(90.0f, Vector3.up);
    */
                this.transform.position = Vector3.MoveTowards(this.transform.position, mpAlberto.transform.position, 1.0f);

            }

            else
            {
                base.DoRatote();
                this.transform.position = Vector3.MoveTowards(this.transform.position, this.transform.forward, 1.0f);
                Debug.Log("Not Find Circle");
            }

            yield return new WaitForSeconds(1.0f);
            //yield waitforseconds 코루틴
            //끝나지 않았지만 리턴
            //코루틴 : 싱글스레드인데 멀티 스레드처럼 보이게 만든 것
        }
    }

}

// Raycast, Coroutine 중요