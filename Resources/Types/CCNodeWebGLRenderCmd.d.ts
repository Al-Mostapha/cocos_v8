
// ------------------------------ The cc.Node's render command for WebGL ----------------------------------
declare module cc {
    class NodeWebGLRenderCmd {
        _node: cc.Node;
        _anchorPointInPoints: cc.Point;
        _displayedColor: cc.Color;
        _glProgramState: cc.GLProgramState;
        constructor (renderable: cc.Node);
        _rootCtor(renderable: cc.Node) : void; // constructor
        _updateColor(): void;
        setShaderProgram(shaderProgram: cc.GLProgram): void
        getShaderProgram(): cc.GLProgram;
        getGLProgramState(): cc.GLProgramState;
        setGLProgramState(glProgramState: cc.GLProgramState): void;
        get _shaderProgram(): cc.GLProgram;
        set _shaderProgram(value: cc.GLProgram);
    }
}


