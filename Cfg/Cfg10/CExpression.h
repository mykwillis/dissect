#ifndef _CEXPRESSION_H
#define _CEXPRESSION_H

class CExpression
{
public:
	static EXPRESSION *CreateBinaryExpression( OPERATION Operation, OPERAND& Operand1, OPERAND& Operand2 )
	{
		EXPRESSION *Expression = new EXPRESSION;
		Expression->Type = EXPR_BINARY;
		Expression->BinaryExpression.Operation = Operation;
		Expression->BinaryExpression.Operand1 = CreateOperandExpression(Operand1);
		Expression->BinaryExpression.Operand2 = CreateOperandExpression(Operand2);
		return Expression;
	}
	static EXPRESSION *CreateUnaryExpression( OPERATION Operation, OPERAND& Operand )
	{
		EXPRESSION *Expression = new EXPRESSION;
		Expression->Type = EXPR_UNARY;
		Expression->UnaryExpression.Operation = Operation;
		Expression->UnaryExpression.Operand = CreateOperandExpression(Operand);
		return Expression;
	}
	static EXPRESSION *CreateOperandExpression( OPERAND& Operand )
	{
		EXPRESSION *Expression = new EXPRESSION;
		Expression->Type = EXPR_OPERAND;
		Expression->Operand = Operand;
		return Expression;
	}

	static void DestroyExpression(EXPRESSION *Expression)
	{
		switch(Expression->Type)	{
		case EXPR_OPERAND:
			delete Expression;
			break;
		case EXPR_UNARY:
			DestroyExpression(Expression->UnaryExpression.Operand);
			delete Expression;
			break;
		case EXPR_BINARY:
			DestroyExpression(Expression->BinaryExpression.Operand1);
			DestroyExpression(Expression->BinaryExpression.Operand2);
			delete Expression;
			break;
		default:
			_ASSERT(0);
			break;
		}
	}

};

#endif // _CEXPRESSION_H