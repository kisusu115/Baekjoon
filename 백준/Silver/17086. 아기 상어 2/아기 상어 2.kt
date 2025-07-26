import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue

private val br = BufferedReader(InputStreamReader(System.`in`))
private var N = 0; private var M = 0
private lateinit var arr: Array<Array<Int>>

private val dx = arrayOf(1, 1, 1, 0, -1, -1, -1, 0)
private val dy = arrayOf(1, 0, -1, -1, -1, 0, 1, 1)

class Node(var y:Int, var x:Int, var depth:Int = 0) {

}

fun main(){
    val l0 = br.readLine().split(" ")
    N = l0[0].toInt(); M = l0[1].toInt()
    arr = Array(N) { Array(M) { 0 } }

    for(i in 0..N-1){
        val lineArr = br.readLine().split(" ")
        for(j in 0..M-1){
            arr[i][j] = lineArr[j].toInt()
        }
    }

    var maxD = Int.MIN_VALUE
    for(i in 0..N-1){
        for(j in 0..M-1){
            var d = getMinDist(i, j)
            maxD = Math.max(maxD, d)
        }
    }
    println(maxD)
}

fun getMinDist(i:Int, j:Int): Int{
    if(arr[i][j] == 1) return 0

    var visited = Array(N) { Array(M) { false } }
    val q: Queue<Node> = LinkedList()

    q.add(Node(i, j, 0))

    while(!q.isEmpty()){
        val polled = q.poll()
        val depth = polled.depth

        for(i in 0..7){
            val nx = polled.x+dx[i]
            val ny = polled.y+dy[i]

            if(nx<0 || nx>=M || ny<0 || ny>=N) continue
            if(visited[ny][nx]) continue
            visited[ny][nx] = true

            if(arr[ny][nx] == 1) return depth+1
            q.add(Node(ny, nx, depth+1))
        }
    }

    return -1
}