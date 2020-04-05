
template<typename FPPrecision, typename IPrecision>
class Sparse {

protected:
	bool mNonZeroStructureSet = false;

public:

	virtual void matrixVectorProduct(FPPrecision *vec_multiplier, FPPrecision *vec_result) = 0;
	virtual void setValue(IPrecision &row, IPrecision &col, FPPrecision &value) = 0;
	virtual void setValues(IPrecision *rows, unsigned nrows, IPrecision *cols, unsigned ncols, FPPrecision *values) = 0;
	virtual void printDense() = 0;

};


template<typename FPPrecision, typename IPrecision>
class ELLPACK : public Sparse {

private:
	unsigned mNonZerosPerRow;
	IPrecision * mColumns;
	FPPrecision * mValues;

public:
	void matrixVectorProduct(FPPrecision *vec_multiplier, FPPrecision *vec_result);
	void setValue(IPrecision &row, IPrecision &col, FPPrecision &value);
	void setValues(IPrecision *rows, unsigned nrows, IPrecision *cols, unsigned ncols, FPPrecision *values);
	void printDense();

};
