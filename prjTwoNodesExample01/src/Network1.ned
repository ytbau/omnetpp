package prjtwonodesexample01.src;

simple Node
{
    gates:
        input in;
        output out;
}

network Network1
{
    @display("bgb=400,200");
    submodules:
        node1: Node {
            @display("p=120,80");
        }
        node2: Node {
            @display("p=300,120");
        }
    connections:
        node1.out --> node2.in;
        node2.out --> node1.in;
}
